#include <iostream>
#include <vector>
using namespace std;

int f(int l, int b, vector<vector<int>> &prices) {
    int m = prices.size();
    int n = prices[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= l; ++i) {
        for (int j = 1; j <= b; ++j) {
            int hori = 0, vert = 0, nocut = prices[i - 1][j - 1];
            for (int k = 1; k <= i; ++k) {
                hori = max(hori, dp[k][j] + dp[i - k][j]);
            }
            for (int k = 1; k <= j; ++k) {
                vert = max(vert, dp[i][k] + dp[i][j - k]);
            }
            dp[i][j] = max(nocut, max(hori, vert));
        }
    }
    return dp[l][b];
}

int main() {
    int m = 2, n = 3;
    vector<vector<int>> prices(m, vector<int>(n));
    prices[0][0] = 2;
    prices[0][1] = 4;
    prices[0][2] = 1;
    prices[1][0] = 4;
    prices[1][1] = 1;
    prices[1][2] = 3;
    cout << f(m, n, prices) << endl;
    return 0;
}