#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

// Dint use Memoization DP
// Tried to use bitmasking as dynamic approach in previous submission gave time limit exceeded at test case 3
int countValidSubsequences(int x, const std::vector<int>& numbers) {
    int count = 0;
    
    for (int mask = 0; mask < (1 << numbers.size()); ++mask) {
        int current_OR = 0;
        
        for (int i = 0; i < numbers.size(); ++i) {
            if (mask & (1 << i)) {
                current_OR |= numbers[i];
            }
        }
        
        if (current_OR == x) {
            ++count;
            count %= MOD;
        }
    }
    return count;
}

int main() {
    int Q;
    // Here, we have to use std::cin because without using it I had got compilation error
    std::cin >> Q;
    // Here, we have to use std::vector because without using it I had got compilation error
    std::vector<int> numbers;
    
    while (Q--) {
        int M, x;
        // Here, we have to use std::cin because without using it I had got compilation error
        std::cin >> M >> x;
        
        if (M == 1) {
            numbers.push_back(x);
        } else {
            // Here, we have to use std::cout because without using it I had got compilation error
            std::cout << countValidSubsequences(x, numbers) << std::endl;
        }
    }
    return 0;
}