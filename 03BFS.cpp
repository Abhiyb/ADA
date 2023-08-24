#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& adj, int start) {
    int V = adj.size();
    vector<bool> visited(V, false);
    
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "Nodes reachable from node " << start << " are:" << endl;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of nodes and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    cout << "Enter edges (u v) for the graph:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Directed graph
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    bfs(adj, startNode);

    return 0;
}
