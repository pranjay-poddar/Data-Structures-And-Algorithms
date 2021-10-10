#include <sstream>
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stack> 
#include <unordered_map>
#include <utility>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const int mod=1e9+7;
#define rep(i,a,b) for (int i = a; i < b; i++)
#define  vec vector<ll>
// Topological sort
// linear ordering of veritces such that for a pair u->v 
// u appear befor v in that order
// topo is valid only for directed and acycl;ic graphs
// Using DFs traversal
// Time complexity O(n+e) space O(n)+O(n)
stack<int>st;
void dfs(int node,vector<int>visit,vector<int>adj[]){
  visit[node]=1;
  for(auto it:adj[node]){
    if(!visit[it]){
      dfs(it,visit,adj);
    }
  }
   st.push(node);// when function call return then then from that
   // node we insert it in the stack
}
void Toposort(int v,vector<int>adj[]){
  vector<int>visit(v+1);
  for(int i=1;i<=v;i++){
    if(!visit[i]){
         dfs(i,visit,adj);
    }
  }
  
}
void solve(){
   
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in1.txt","r",stdin);
        freopen("out1.txt","w",stdout);
    #endif


    int t=1;
    cin>>t;
    while(t--){
     solve();
    }
    return 0;
}
