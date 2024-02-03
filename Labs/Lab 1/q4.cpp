#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

bool canAchieveSum(const vector<int>& array, int x) {
    int maxStat = *max_element(array.begin(), array.end());
    int minStat = *min_element(array.begin(), array.end());
    int mid = floor((maxStat + minStat) / 2);

    vector<int> leftArray, rightArray;
    for (int stat : array) {
        if (stat <= mid) {
            leftArray.push_back(stat);
        } else {
            rightArray.push_back(stat);
        }
    }

    int leftSum = accumulate(leftArray.begin(), leftArray.end(), 0);
    int rightSum = accumulate(rightArray.begin(), rightArray.end(), 0);

    if (leftSum == x || rightSum == x || leftSum + rightSum == x) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int t;
    cin >> t;

    vector<string> results;

    for (int i = 0; i < t; ++i) {
        int n, q;
        cin >> n >> q;

        vector<int> array(n);
        for (int j = 0; j < n; ++j) {
            cin >> array[j];
        }

        for (int k = 0; k < q; ++k) {
            int a;
            cin >> a;
            bool result = canAchieveSum(array, a);
            results.push_back(result ? "Yes" : "No");
        }
    }

    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}