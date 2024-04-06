#include <iostream>
#include <vector>

const int MOD = 1e9+7;

int countSubsequences(int i, int current_OR, int x, const std::vector<int>& numbers) {
    if (i == numbers.size()) {
        return current_OR == x;
    }
    
    int include = countSubsequences(i + 1, current_OR | numbers[i], x, numbers);
    
    int exclude = countSubsequences(i + 1, current_OR, x, numbers);
    
    return (include + exclude) % MOD;
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
            std::cout << countSubsequences(0, 0, x, numbers) << std::endl;
        }
    }
    return 0;
}