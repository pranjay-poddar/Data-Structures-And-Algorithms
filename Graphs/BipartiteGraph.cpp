#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> v; //for storing vertices
vector<bool> vis;      //stores whether a vertex is visited or not
vector<int> col;       //stores colour (represented by 0 or 1) of vertices
bool bipartite=true;   //initially we assume the graph is bipartite

void colour(int node, int curr){
    if(vis[node] && col[node]!=curr){   //node is already visited but contains a different colour
        bipartite=false;
    }
    if(!vis[node]){
        vis[node]=true;
        col[node]=curr;
        bipartite=true;
        for(auto i: v[node]){        //traverse all the vertices associated with node
            colour(i,curr^1);
        }
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    v=vector<vector<int>>(n);
  
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
  
    vis=vector<bool>(n,false);
    col=vector<int>(n,-1);
  
    for(int i=0;i<n;i++){   //visit all the vertices
        if(!vis[i]){
            colour(i,0);    
        }
    }
    if(bipartite){
        cout<<"Graph is bipartite";
    }
    else{
        cout<<"Graph is not bipartite";
    }
    return 0;
}
