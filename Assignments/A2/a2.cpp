#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxChickens(vector<int>& A) {
    int n = A.size();
    
    vector<vector<vector<int>>> DP(n + 1, vector<vector<int>>(2, vector<int>(4, 0)));
    
    DP[1][0][1] = max(A[0], 0);
    DP[1][1][1] = max(-A[0], 0);

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= 1; ++j) {
            for (int k = 1; k <= 3; ++k) {
                int reward_penalty = (j == 0) ? (A[i - 1] > 0 ? A[i - 1] : -A[i - 1]) : (A[i - 1] < 0 ? -A[i - 1] : A[i - 1]);
                
                if (k < 3) {
                    DP[i][j][k] = max(DP[i - 1][j][k + 1] + reward_penalty, DP[i - 1][1 - j][1] + reward_penalty);
                } else {
                    DP[i][j][k] = DP[i - 1][1 - j][1] + reward_penalty;
                }
            }
        }
    }
    
    return max(DP[n][0][1], DP[n][1][1]);
}

int main() {
    vector<int> A = {1, -2, 3, -4, 5};
    
    int maxChickensEarned = maxChickens(A);
    
    cout << "Maximum number of chickens earned by Mr. Fox: " << maxChickensEarned << endl;
    
    return 0;
}