// Tabulation - Bottom Up Approach
// Time Complexity is O(n).
// Space Complexity is O(1).
// Print the fibonacci using Tabulation and Optimizing Space.

#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int> &dp) {
    if (n <= 1) {
        return n;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    for (int i = 0; i < n; i++) {
        dp[i + 2] = dp[i] + dp[i + 1];
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    int prev2 = 0;
    int prev = 1;
    for(int i=2; i<=n; i++){
        int cur_i = prev2+ prev;
        prev2 = prev;
        prev= cur_i;
    }
    cout << prev;
    cout << endl;
    return 0;
}