// Tabulation - Bottom Up Approach
// Time Complexity is O(n).
// Space Complexity is O(1).
// Print the fibonacci using Tabulation.

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
    dp[0] = 0;
    dp[1] = 1;
    cout << fib(n, dp) << endl;
    cout << "dp array: ";
    for (int i = 0; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    return 0;
}