
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&adj,vector<bool>&visited,int start)
{
      visited[start]=true;
      for(auto it:adj[start])
      {
          if(!visited[it])
          {
              dfs(adj,visited,it);
          }
      }
}

int main()
{
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
    vector<bool>vis(V,false);
    dfs(adj,vis,0);
    for(bool it:vis)
    {
        if(!it){
        cout<<"not connected"; return 0;
        }
    }
    cout<<"connected";
    return 0;
}
