#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(adj, visited, neighbor);
        }
    }
}

bool isConnected(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);

    // Start DFS from the first node
    dfs(adj, visited, 0);

    // Check if all nodes were visited
    for (bool status : visited) {
        if (!status) {
            return false;
        }
    }

    return true;
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
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    if (isConnected(adj, V)) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    return 0;
}
