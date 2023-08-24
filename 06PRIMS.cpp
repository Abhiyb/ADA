#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<pair<int, int>>>& adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);
    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if (vis[node] == 1) continue;
        vis[node] = 1;
        sum += wt;
        for (auto edge : adj[node]) {
            int adjnode = edge.first; 
            int ewt = edge.second;    
            if (!vis[adjnode]) {
                pq.push({ewt, adjnode});
            }
        }
    }
    return sum;
}

int main() {
    int V,E;
     cout<<"Enter no of vertex and edges";
     cin>>V>>E;
    vector<vector<pair<int, int>>> adj(V);
     cout<<"enter edge (u,v,w)"<<endl;
    //--------------------take input from user---------------
   for(int i=0;i<E;i++)
   {
       int u,v,w;
       cin>>u>>v>>w;
       adj[u].push_back({v,w});
       adj[v].push_back({u,w});
   }
//------------------------OR----------------------------
    // adj[0].push_back({1, 2});
    // adj[1].push_back({0, 2});
    // adj[0].push_back({2, 4});
    // adj[2].push_back({0, 4});
    // adj[1].push_back({2, 1});
    // adj[2].push_back({1, 1});
    // adj[1].push_back({3, 7});
    // adj[3].push_back({1, 7});
    // adj[2].push_back({4, 3});
    // adj[4].push_back({2, 3});
    // adj[3].push_back({4, 5});
    // adj[4].push_back({3, 5});

    // vector<int> vec;
    int minimumCost = spanningTree(V, adj);
    cout << "Minimum Cost: " << minimumCost << endl;

    return 0;
}
