#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int check(vector<int> & nums, int ind, int rc, int dc, vector<vector<vector<int>>> dp) {
    if (ind == 0) {
        if (rc == 3) {
            return -nums[ind];
        }
        if (dc == 3) {
            return nums[ind];
        }
        if (nums[ind] > 0) {
            return nums[ind];
        } else if (nums[ind] < 0) {
            return -nums[ind];
        }
    }
    if (dp[ind][rc][dc] != INT_MIN) {
        return dp[ind][rc][dc];
    }
    int ring = INT_MIN;
    int ding = INT_MIN;
    if (rc == 3) {
        ding = check(nums, ind - 1, 0, 1, dp) - nums[ind];
    } else if (dc == 3) {
        ring = check(nums, ind - 1, 1, 0, dp) + nums[ind];
    } else {
        ring = check(nums, ind - 1, rc + 1, 0, dp) + nums[ind];
        ding = check(nums, ind - 1, 0, dc + 1, dp) - nums[ind];
    }
    dp[ind][rc][dc] = max(ring, ding);
    return max(ring, ding);
}

int main() {
    vector<int> nums {2, 4, 5, 6, -3, -7, 1, -4, 5, -7};
    int n = nums.size();
    vector<vector<int>> a(4, vector<int>(4, INT_MIN));
    vector<vector<vector<int>>> dp (n, a);
    cout << check(nums, n - 1, 0, 0, dp);
    return 0;
}