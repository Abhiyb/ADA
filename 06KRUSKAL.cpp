#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int>&e1,vector<int>&e2)
{
    return e1[0]<e2[0];
}
int findparent(int x,vector<int>&parent)
{
    if(x!=parent[x])
    {
        parent[x]=findparent(parent[x],parent);
    }return parent[x];
}
void unionset(int x,int y,vector<int>&parent,vector<int>&rank)
{
    int x_root=findparent(x,parent);
    int y_root=findparent(y,parent);
    if(x_root!=y_root)
    {
        if(rank[x_root]>rank[y_root])
        {
            parent[y_root]=x_root;
        }
        else if(rank[x_root]<rank[y_root])
        {
            parent[x_root]=y_root;
        }
        else{
            rank[x_root]++;
            parent[y_root]=x_root;
        }
    }
}
int kruskal(vector<vector<int>>&edges,int n)
{
      vector<int>parent(n);
      vector<int>rank(n,0);  
      for(int i=0;i<n;i++)
      {
          parent[i]=i;
      } int ans=0;
      sort(edges.begin(),edges.end(),compare);
      for(const auto& it:edges)
      {
          int src=it[1];int dest=it[2];
          if(findparent(src,parent)!=findparent(dest,parent))
          {
              ans+=it[0];
              unionset(src,dest,parent,rank);
          }
      } return ans;
}
int main()
{
    // cout<<"Hello World";
// vector<vector<int>>adj={ {8,1,5},{7,4,5},{6,2,6},{5,3,6},{4,3,4},{3,2,3},{2,1,2},{1,1,4}};
vector<vector<int>> adj = {{8, 1, 5}, {7, 4, 5}, {6, 2, 6}, {5, 3, 6}, {4, 3, 4}, {3, 2, 3}, {2, 1, 2}, {1, 1, 4}};

int result=kruskal(adj,7);
cout<<result;
}
