#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

// Structure to represent a box
struct Box {
    int height, width, depth;

    // Constructor for ease of use
    Box(int h, int w, int d) : height(h), width(w), depth(d) {}

    // Function to check if this box can be nested inside another box 'b'
    bool canNestInside(const Box& b) const {
        // Checking all rotations
        return (height < b.height && width < b.width && depth < b.depth) ||
               (height < b.width && width < b.depth && depth < b.height) ||
               (height < b.depth && width < b.height && depth < b.width);
    }
};

// Function to add edges to the flow graph
void addEdge(vector<vector<int>>& capacity, int from, int to) {
    capacity[from][to] = 1;  // Capacity is 1, as each box can be placed only once
}

// Find maximum flow using Ford-Fulkerson algorithm with BFS (Edmonds-Karp Implementation)
int fordFulkerson(vector<vector<int>>& capacity, int source, int sink) {
    int totalFlow = 0;
    int numVertices = capacity.size();
    vector<vector<int>> residualCapacity = capacity;

    while (true) {
        vector<int> parent(numVertices, -1);
        queue<int> q;
        q.push(source);
        parent[source] = source;

        // BFS to find the shortest augmenting path
        while (!q.empty() && parent[sink] == -1) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < numVertices; ++v) {
                if (parent[v] == -1 && residualCapacity[u][v] > 0) {
                    parent[v] = u;
                    q.push(v);
                    if (v == sink) break; // Stop BFS once we reach the sink
                }
            }
        }

        // If no augmenting path is found, break the loop
        if (parent[sink] == -1) break;

        // Find the maximum flow through the path found.
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualCapacity[u][v]);
        }

        // Update residual capacities of the edges and reverse edges along the path
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualCapacity[u][v] -= pathFlow;
            residualCapacity[v][u] += pathFlow;
        }

        totalFlow += pathFlow;
    }

    return totalFlow;
}

int main() {
    int n;
    cout << "Enter number of boxes: ";
    cin >> n;

    vector<Box> boxes;
    cout << "Enter dimensions (h w d) for each box:\n";
    for (int i = 0; i < n; ++i) {
        int h, w, d;
        cin >> h >> w >> d;
        boxes.emplace_back(h, w, d);
    }

    int source = n, sink = n + 1;
    vector<vector<int>> capacity(n + 2, vector<int>(n + 2, 0));

    // Construct the flow network
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && boxes[i].canNestInside(boxes[j])) {
                addEdge(capacity, i, j);
            }
        }
    }

    // Connect source to all nodes and all nodes to sink
    for (int i = 0; i < n; ++i) {
        addEdge(capacity, source, i);
        addEdge(capacity, i, sink);
    }

    // Compute the minimum number of visible boxes
    int minVisibleBoxes = n - fordFulkerson(capacity, source, sink);
    cout << "Minimum number of visible boxes: " << minVisibleBoxes << endl;

    return 0;
}