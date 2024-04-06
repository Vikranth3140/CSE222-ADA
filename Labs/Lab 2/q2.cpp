#include <iostream>
#include <vector>

const int MOD = 1e9+7;

// Recursive function to calculate the count of valid subsequences
int countSubsequences(int idx, int currentOR, int x, const std::vector<int>& numbers) {
    // Base case: if we've considered all elements
    if (idx == numbers.size()) {
        return currentOR == x;
    }
    
    // Include the current element in the OR
    int include = countSubsequences(idx + 1, currentOR | numbers[idx], x, numbers);
    
    // Exclude the current element
    int exclude = countSubsequences(idx + 1, currentOR, x, numbers);
    
    // Return the sum of both choices
    return (include + exclude) % MOD;
}

int main() {
    int Q;
    std::cin >> Q;
    
    std::vector<int> numbers;
    
    while (Q--) {
        int M, x;
        std::cin >> M >> x;
        
        if (M == 1) {
            // Mode 1: Store the number
            numbers.push_back(x);
        } else {
            // Mode 2: Calculate and output the special key
            std::cout << countSubsequences(0, 0, x, numbers) << std::endl;
        }
    }
    
    return 0;
}