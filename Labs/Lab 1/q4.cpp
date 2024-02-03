#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool canAchieveSum(vector<int>& array, int x) {
    int maxStat = *max_element(array.begin(), array.end());
    int minStat = *min_element(array.begin(), array.end());

    if (maxStat == minStat) {
        return minStat == x;
    }

    int mid = floor((maxStat + minStat) / 2);

    vector<int> leftArray, rightArray;

    // Separate elements into left and right arrays
    for (int stat : array) {
        if (stat <= mid) {
            leftArray.push_back(stat);
        } else {
            rightArray.push_back(stat);
        }
    }

    int leftSum = 0, rightSum = 0;

    // Calculate leftSum using a loop
    for (int stat : leftArray) {
        leftSum += stat;
    }

    // Calculate rightSum using a loop
    for (int stat : rightArray) {
        rightSum += stat;
    }

    // Clear elements greater than mid
    for (int i = array.size() - 1; i >= 0; --i) {
        if (array[i] > mid) {
            array.erase(array.begin() + i);
        }
    }

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