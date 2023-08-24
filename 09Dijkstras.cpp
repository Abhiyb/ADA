#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>distto(V,INT_MAX);
        pq.push({0,S}); 
        distto[S]=0;
        while(!pq.empty())
        {
            int dis=pq.top().first;
            int node=pq.top().second;pq.pop();
            for(auto it:adj[node])
            {
                int v=it[0];
                int w=it[1];
                if(dis+w<distto[v])
                {
                    distto[v]=w+dis;
                    // pq.push({dist[adjnode],adjnode});
                    pq.push({dis + w, v});
                    // pq.push({adjnode,dist[adjnode]});
                }
            }
        } return distto;
        
    }
    int main() {
    cout << "Enter the number of vertices and edges: ";
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj[V]; // Adjacency list representation of graph

    cout << "Enter the edges and their weights (u v w):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Assuming undirected graph
    }

    int sourceNode;
    cout << "Enter the source node: ";
    cin >> sourceNode;

    vector<int> shortestDistances = dijkstra(V, adj, sourceNode);

    cout << "\nShortest distances from node " << sourceNode << " to all other nodes:\n";
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << ": " << shortestDistances[i] << "\n";
    }

    return 0;
}
