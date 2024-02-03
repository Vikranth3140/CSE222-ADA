#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

bool sum_coming(const vector<int>& array, int x) {
    int max = *max_element(array.begin(), array.end());
    int min = *min_element(array.begin(), array.end());
    int mid = floor((max + min) / 2);

    vector<int> left_array, right_array;
    for (int stat : array) {
        if (stat <= mid) {
            left_array.push_back(stat);
        } else {
            right_array.push_back(stat);
        }
    }

    int left_sum = accumulate(left_array.begin(), left_array.end(), 0);
    int right_sum = accumulate(right_array.begin(), right_array.end(), 0);

    if (left_sum == x || right_sum == x || left_sum + right_sum == x) {
        return true;
    } else {
        return false;
    }

    // if (left_sum != x && right_sum != x && left_sum + right_sum != x) {
    //     return false;
    // } else {
    //     return true;
    // }
}

int main() {
    int no;
    cin >> no;

    vector<string> results;

    for (int i = 0; i < no; ++i) {
        int n, q;
        cin >> n >> q;

        vector<int> array(n);
        for (int j = 0; j < n; ++j) {
            cin >> array[j];
        }

        for (int k = 0; k < q; ++k) {
            int a;
            cin >> a;
            bool result = sum_coming(array, a);
            results.push_back(result ? "Yes" : "No");
        }
    }

    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}