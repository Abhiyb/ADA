#include <bits/stdc++.h>
using namespace std;
void bfs(vector<int>adj[],int v,int e){
    vector<int>visited(v,0);
    queue<int>q;
    q.push(0);
    visited[0]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(auto x:adj[curr]){
            if(!visited[x]){
                visited[x]=1;
                q.push(x);
            }
        }
    }
    cout<<endl;
}
int main()
{  int v,e;
   cout<<"enter v,e";
   cin>>v>>e;
    vector<int>adj[v];
    for(int i=0;i<e;i++){
        cout<<"enter edge";
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>visited(v,0);
    bfs(adj,v,e);
    // dfs(adj,0,visited);
    return 0;
}
