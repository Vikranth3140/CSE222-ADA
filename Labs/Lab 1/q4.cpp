#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

bool sum_coming_recursive(const vector<int>& array, int x, int start, int end) {
    if (start >= end) {
        return false;
    }

    int max_val = *max_element(array.begin() + start, array.begin() + end);
    int min_val = *min_element(array.begin() + start, array.begin() + end);
    int mid = floor((max_val + min_val) / 2);

    vector<int> left_array, right_array;
    for (int i = start; i < end; ++i) {
        if (array[i] <= mid) {
            left_array.push_back(array[i]);
        } else {
            right_array.push_back(array[i]);
        }
    }

    int left_sum = accumulate(left_array.begin(), left_array.end(), 0);
    int right_sum = accumulate(right_array.begin(), right_array.end(), 0);

    if (x < left_sum) {
        return sum_coming_recursive(left_array, x, 0, left_array.size());
    } else if (x > right_sum) {
        return sum_coming_recursive(right_array, x, 0, right_array.size());
    } else {
        return true; // x is between left_sum and right_sum, so return true
    }
}

bool sum_coming(const vector<int>& array, int x) {
    return sum_coming_recursive(array, x, 0, array.size());
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