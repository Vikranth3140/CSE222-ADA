#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <functional>

using namespace std;

// Define a structure for representing a box
struct Box {
    int height;
    int width;
    int depth;
};

// Function to check if box1 can be nested inside box2
bool canNest(const Box& box1, const Box& box2) {
    return box1.height < box2.height && box1.width < box2.width && box1.depth < box2.depth;
}

int main() {
    vector<Box> boxes = {{15, 15, 15}, {12, 12, 12}, {18, 18, 18}};
    int numBoxes = boxes.size();
    int source = 0, sink = numBoxes + 1;

    // Construct flow network graph
    vector<vector<int>> graph(numBoxes + 2, vector<int>(numBoxes + 2, 0));
    for (int i = 0; i < numBoxes; ++i) {
        graph[source][i + 1] = 1; // Edge from source to box
        graph[i + 1][sink] = 1;   // Edge from box to sink
        for (int j = i + 1; j < numBoxes; ++j) {
            if (canNest(boxes[i], boxes[j])) {
                graph[i + 1][j + 1] = 1; // Edge between boxes if nesting is possible
            }
        }
    }

    // Ford-Fulkerson's algorithm to find maximum flow in a flow network
    vector<int> parent(numBoxes + 2);
    int maxFlow = 0;

    // Augment the path in the residual graph using DFS
    function<bool(int, int)> dfs = [&](int u, int minCapacity) {
        if (u == sink) {
            maxFlow += minCapacity;
            int v = sink;
            while (v != source) {
                int u = parent[v];
                graph[u][v] -= minCapacity;
                graph[v][u] += minCapacity;
                v = u;
            }
            return true;
        }
        for (int v = 0; v < numBoxes + 2; ++v) {
            if (graph[u][v] > 0 && parent[v] == -1) {
                parent[v] = u;
                if (dfs(v, min(minCapacity, graph[u][v]))) {
                    return true;
                }
            }
        }
        return false;
    };

    while (true) {
        fill(parent.begin(), parent.end(), -1);
        parent[source] = source;
        if (!dfs(source, numeric_limits<int>::max())) {
            break;
        }
    }

    cout << "Maximum nesting of boxes: " << maxFlow << endl;
    return 0;
}