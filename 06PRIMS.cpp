#include<bits/stdc++.h>
using namespace std;
int spanningTree(int V, vector<vector<int>> adj[],vector<int>&vec)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(V,0);
        pq.push({0,0}); int sum=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;
            if(vis[node]==1)continue;
            vis[node]=1;
            sum+=wt;
            vec.push_back(node);
            for(auto it:adj[node])
            {
                int adjnode=it[0];
                int ewt=it[1];
                if(!vis[adjnode])
                {
                    pq.push({ewt,adjnode});
                }
            }
        }return sum;
    }
int main() {
    int V = 4; 
    vector<vector<int>> adj[V];
    
  adj[0].push_back({1,2});
  adj[1].push_back({0,2});
  adj[0].push_back({2,5});
  adj[1].push_back({2,3});
  adj[1].push_back({3,2});
  adj[2].push_back({3,4});
  adj[2].push_back({0,5});
    vector<int>vec;
    int minimumCost = spanningTree(V, adj,vec);
    cout<<minimumCost;

    return 0;
}
