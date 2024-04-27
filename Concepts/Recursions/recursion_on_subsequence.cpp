// Time Complexity is O(2^n * n).
// Space Complexity is O(n).
// Print all the subsequences of an array using recursion.

#include <iostream>
#include <vector>
using namespace std;

void printSubsequences(int index, vector<int> &array, int arr[], int n) {

    if (index >= n) {
        for (auto it : array) {
            cout << it << " ";
        }
        if (array.size() == 0) {
            cout << "{}";
        }
        cout << endl;
        return;
    }

    array.push_back(arr[index]);
    printSubsequences(index + 1, array, arr, n);
    array.pop_back();

    printSubsequences(index + 1, array, arr, n);
}

int main() {
    int arr[] = {3, 1, 2};
    int n = 3;
    
    vector<int> array;

    printSubsequences(0, array, arr, n);
    return 0;
}