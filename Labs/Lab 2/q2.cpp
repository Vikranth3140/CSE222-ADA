#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;
const int MAX_X = 1024;

// Went back to DP as Time Complexity of Bitmasking is O(2^n)
void updateDP(std::vector<std::vector<int>>& dp, const std::vector<int>& numbers, int start_i) {
    int n = numbers.size();
    for (int i = start_i; i < n; ++i) {
        for (int j = 0; j < MAX_X; ++j) {
            int new_OR = j | numbers[i];
            dp[i + 1][new_OR] += dp[i][j];
            dp[i + 1][new_OR] %= MOD;

            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= MOD;
        }
    }
}

int main() {
    int Q;
    // Here, we have to use std::cin because without using it I had got compilation error
    std::cin >> Q;
    // Here, we have to use std::vector because without using it I had got compilation error
    std::vector<int> numbers;
    // Here, we have to use std::vector because without using it I had got compilation error
    std::vector<std::vector<int>> dp(1, std::vector<int>(MAX_X, 0));

    dp[0][0] = 1;
    int updated_i = 0;

    while (Q--) {
        int M, x;
        // Here, we have to use std::cin because without using it I had got compilation error
        std::cin >> M >> x;

        if (M == 1) {
            numbers.push_back(x);
        } else {
            if (numbers.size() > dp.size() - 1) {
                // Here, we have to use std::vector because without using it I had got compilation error
                dp.resize(numbers.size() + 1, std::vector<int>(MAX_X, 0));
                updateDP(dp, numbers, updated_i);
                updated_i = numbers.size();
            }
            // Here, we have to use std::cout and std::endl because without using it I had got compilation error
            std::cout << dp[numbers.size()][x] << std::endl;
        }
    }
    return 0;
}