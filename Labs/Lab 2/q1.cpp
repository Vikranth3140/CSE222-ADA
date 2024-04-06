#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>

using namespace std;

const int MAX_CONTAINERS = 100;
const int MAX_CAPACITY = 1000;
const int INF = numeric_limits<int>::max();

int dp[MAX_CONTAINERS + 1][MAX_CAPACITY + 1];

int solve(vector<int>& x, vector<int>& y, int n, int remCapacity) {
    if (remCapacity == 0) {
        return 0;
    }

    if (n == 0) {
        return INF;
    }

    if (dp[n][remCapacity] != -1) {
        return dp[n][remCapacity];
    }

    int ans = INF;
    ans = min(ans, solve(x, y, n - 1, remCapacity));
    int transfer = min(remCapacity, x[n - 1]);
    ans = min(ans, transfer + solve(x, y, n - 1, remCapacity - transfer));

    return dp[n][remCapacity] = ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    memset(dp, -1, sizeof(dp));

    int totalCapacity = 0;
    for (int cap : y) {
        totalCapacity += cap;
    }

    int minEffort = solve(x, y, n, totalCapacity);

    int minContainers = 0;
    for (int i = 0; i < n; i++) {
        if (solve(x, y, n, totalCapacity - y[i]) == minEffort) {
            minContainers++;
        }
    }

    cout << minContainers << " " << minEffort << endl;

    return 0;
}