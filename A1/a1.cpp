#include <iostream>
#include <vector>

using namespace std;

// Recursive binary search function to find the count of elements less than or equal to target in a sorted array
int recursiveBinarySearchCount(const vector<int>& arr, int target, int low, int high) {
    if (low > high) {
        return 0;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] <= target) {
        // Elements less than or equal to target are in the right half
        return mid - low + 1 + recursiveBinarySearchCount(arr, target, mid + 1, high);
    } else {
        // Elements less than or equal to target are in the left half
        return recursiveBinarySearchCount(arr, target, low, mid - 1);
    }
}

// Function to find the k-th smallest element in A ∪ B ∪ C
int kthSmallestElement(const vector<int>& A, const vector<int>& B, const vector<int>& C, int k) {
    int low = min(min(A[0], B[0]), C[0]);
    int high = max(max(A.back(), B.back()), C.back());

    while (low < high) {
        int mid = low + (high - low) / 2;

        // Count elements less than or equal to mid in each array using recursive binary search
        int a_count = recursiveBinarySearchCount(A, mid, 0, A.size() - 1);
        int b_count = recursiveBinarySearchCount(B, mid, 0, B.size() - 1);
        int c_count = recursiveBinarySearchCount(C, mid, 0, C.size() - 1);

        int total_count = a_count + b_count + c_count;

        if (total_count < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    // Example usage
    vector<int> A = {1, 3, 5, 7, 9};
    vector<int> B = {2, 4, 6, 8, 10};
    vector<int> C = {11, 13, 15, 17, 19};

    int k = 8;

    int result = kthSmallestElement(A, B, C, k);

    cout << "The " << k << "-th smallest element is: " << result << endl;

    return 0;
}