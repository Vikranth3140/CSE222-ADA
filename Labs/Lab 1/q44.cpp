#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
bool friendly_stat(int left, int right, int target, vector<int>& pokemon) {
    int left_sum = 0;
    int right_sum = 0;
    int total_sum = 0;
 
    if (left > right) {
        return false;
    }
 
    if (pokemon.size()>1 && pokemon[left] == pokemon[right]) {
        return false;
    }
 
    int mid = (pokemon[right] + pokemon[left]) / 2;
    int mid_ind = (left+right)/2;
 
    for (int j = left; j <= right; j++) {
        total_sum += pokemon[j];
        if (pokemon[j] <= mid) {
            left_sum += pokemon[j];
        } else {
            right_sum += pokemon[j];
        }
    }
 
    if (target == total_sum || target == left_sum || target == right_sum) {
        return true;
    }
 
    if (target < left_sum) {
        return friendly_stat(left, mid_ind - 1, target, pokemon);
    }
 
    if (target < right_sum) {
        return friendly_stat(mid_ind+1, right, target, pokemon);
    }
 
    return false;
}
 
int main() {
    int t;
    cin >> t;
 
    vector<string> results;
 
    while (t--) {
        int n, q;
        cin >> n >> q;
 
        vector<int> pokemon(n);
        for (int i = 0; i < n; i++) {
            cin >> pokemon[i];
        }
        sort(pokemon.begin(), pokemon.end());
 
        for (int i = 0; i < q; i++) {
            int target;
            cin >> target;
 
            bool result = friendly_stat(0, n - 1, target, pokemon);
 
            if (result) {
                results.push_back("YES");
            } else {
                results.push_back("NO");
            }
        }
    }
 
    for (const string& result : results) {
        cout << result.c_str() << endl;
    }
 
    return 0;
}