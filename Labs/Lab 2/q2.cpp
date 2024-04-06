#include <iostream>
#include <vector>
#include <unordered_map>

const int MOD = 1e9 + 7;
// Here, we have to use std::unordered_map because without using it I had got compilation error
std::unordered_map<long long, int> memo;

long long make_key(int i, int current_OR) {
    return ((long long)i << 32) | current_OR;
}

int countSubsequences(int i, int current_OR, int x, const std::vector<int>& numbers) {
    if (i == numbers.size()) {
        return current_OR == x;
    }
    
    long long key = make_key(i, current_OR);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }
    
    int include = countSubsequences(i + 1, current_OR | numbers[i], x, numbers);

    int exclude = countSubsequences(i + 1, current_OR, x, numbers);
    
    memo[key] = (include + exclude) % MOD;
    return memo[key];
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
            memo.clear();
            // Here, we have to use std::cout because without using it I had got compilation error
            std::cout << countSubsequences(0, 0, x, numbers) << std::endl;
        }
    }
    return 0;
}