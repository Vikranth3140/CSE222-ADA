#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

bool friendly_stat(int left, int right, int target, const vector<int>& pokemon) {
    if (left > right || (pokemon.size() > 1 && pokemon[left] == pokemon[right])) {
        return false;
    }

    int mid = (pokemon[right] + pokemon[left]) / 2;
    int mid_index = floor((left + right) / 2);

    int left_sum = 0, right_sum = 0, total_sum = 0;

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
        return friendly_stat(left, mid_index - 1, target, pokemon);
    } else if (target < right_sum) {
        return friendly_stat(mid_index + 1, right, target, pokemon);
    }

    return false;
}

int main() {
    int no;
    cin >> no;

    vector<string> results;

    while (no--) {
        int n, q;
        cin >> n >> q;

        vector<int> pokemon(n);
        for (int i = 0; i < n; i++) {
            cin >> pokemon[i];
        }

        sort(pokemon.begin(), pokemon.end());

        for (int i = 0; i < q; i++) {
            int to_reach;
            cin >> to_reach;

            bool result = friendly_stat(0, n - 1, to_reach, pokemon);

            results.push_back(result ? "Yes" : "No");
        }
    }

    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}