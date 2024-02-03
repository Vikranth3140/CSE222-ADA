#include <iostream>
#include <vector>

using namespace std;

bool hasSubsequence(const vector<int>& arr, int n) {
    int m = arr.size();

    for (int j = 1; j < (1 << m); ++j) {
        long long s = 0;
        vector<int> indices;

        for (int i = 0; i < m; ++i) {
            if (j & (1 << i)) {
                s += arr[i];
                indices.push_back(i);
            }
        }

        if (s % n == 0 && indices.size() > 0) {
            return true;
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int m, n;
        cin >> m >> n;

        vector<int> arr(m);
        for (int i = 0; i < m; ++i) {
            cin >> arr[i];
        }

        bool valid = true;

        for (int i = 0; i < m; ++i) {
            vector<int> remainingArr;

            for (int j = 0; j < m; ++j) {
                if (i != j) {
                    remainingArr.push_back(arr[j]);
                }
            }

            if (!hasSubsequence(remainingArr, n)) {
                valid = false;
                break;
            }
        }

        cout << (valid ? "YES" : "NO") << endl;
    }

    return 0;
}