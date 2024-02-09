#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_chickens_earned(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    
    vector<int> dp(n, 0);
    int count = 0;
    for (int ind = 1; ind < n; ind++) {
        if (count == 2) {
            dp[ind] = -dp[ind-1];
            count = 0;
            continue;
        }
        int ring = dp[ind-1] + (nums[ind] > 0 ? nums[ind] : -nums[ind]);
        int ding = dp[ind-1] + (nums[ind] < 0 ? nums[ind] : -nums[ind]);
        dp[ind] = max(ring, ding);
        count++;
    }
    return dp[n-1];
}

int main() {
    vector<int> nums = {3, -1, 4, -5, 6, -7, 8};
    cout << max_chickens_earned(nums) << endl;
    return 0;
}