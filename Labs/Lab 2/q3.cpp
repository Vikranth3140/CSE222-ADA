#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN = 100;
vector<int> graph[MAXN];
vector<bool> visited(MAXN, false);
int n, m;

// Find all increasing paths from a given vertex using DFS
void dfs(int v, vector<int>& path, vector<vector<int>>& all_paths) {
    path.push_back(v);
    visited[v] = true;
    
    // Consider this path as a potential candidate
    all_paths.push_back(path);
    
    // Explore further increasing paths
    for (int next : graph[v]) {
        if (!visited[next] && next > v) {
            dfs(next, path, all_paths);
        }
    }
    
    // Backtrack
    path.pop_back();
    visited[v] = false;
}

// Count the number of external connections ("hands") for a path
int count_hands(const vector<int>& path) {
    set<int> path_nodes(path.begin(), path.end());
    int hands = 0;
    
    for (int v : path) {
        for (int u : graph[v]) {
            // If the neighbor is not in the path, it's an external connection
            if (path_nodes.find(u) == path_nodes.end()) {
                hands++;
            }
        }
    }
    
    return hands;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int max_beauty = 0;
    for (int i = 1; i <= n; i++) {
        vector<int> path;
        vector<vector<int>> all_paths;
        dfs(i, path, all_paths); // Find all increasing paths starting from i
        
        for (auto& p : all_paths) {
            int hands = count_hands(p); // Count hands for each path
            int beauty = p.size() * hands; // Calculate beauty
            max_beauty = max(max_beauty, beauty); // Update max beauty
        }
    }

    cout << max_beauty << endl;

    return 0;
}