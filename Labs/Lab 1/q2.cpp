#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;

    vector<int> team_powers(n);
    for (int i = 0; i < n; ++i) {
        cin >> team_powers[i];
    }

    vector<pair<int, int>> base_info(b);
    for (int i = 0; i < b; ++i) {
        cin >> base_info[i].first >> base_info[i].second;
    }

    sort(base_info.begin(), base_info.end());

    vector<int> prefix(b);
    prefix[0] = base_info[0].second;
    for(int i = 1; i < b; i++) {
        prefix[i] = prefix[i-1] + base_info[i].second;
    }

    vector<int> result;

    for (int i = 0; i < n; ++i) {
        int l = 0, r = b;
        while(l < r) {
            int m = (l + r) / 2;
            if(base_info[m].first <= team_powers[i])
                l = m + 1;
            else
                r = m;
        }
        result.push_back(l > 0 ? prefix[l-1] : 0);
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }

    return 0;
}