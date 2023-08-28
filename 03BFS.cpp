
#include <bits/stdc++.h>

using namespace std;
void bfs(vector<int>adj[],int start,int V)
{
    queue<int>q;q.push(0);  vector<bool>visited(V+1,false); visited[start]=true;
    while(!q.empty())
    {
        int node=q.front();q.pop();
        cout<<node;
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                visited[it]=true; q.push(it);
            }
        }
    }
}
int main()
{
     int V,E;cin>>V>>E;vector<int>adj[V];
     for(int i=0;i<E;i++)
     {
         int u,v;cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
     }
     bfs(adj,0,V);
    return 0;
}
