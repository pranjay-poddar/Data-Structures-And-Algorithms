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
// Detect the Directed cycle using Dfs
// We cannot us the previoius method to find the cycle
// as in  directed graph the arrow should follow clock wise /anti clock wise direction
// Time complexity O(n+e) Space Cpmplexity O(2n)
// Auxilary space O(n) in recursion stack frame
bool chkcycledfs(int node,vector<int> &visit,vector<int>adj[],vector<int> &dfsvisit){
  visit[node]=1;
  dfsvisit[node]=1;
  for(auto it:adj[node]){
    if(!visit[it]){
      if(chkcycledfs(it,visit,adj,dfsvisit)) return true;
    }else if(dfsvisit[it]){
        return true;
    }
  }
  dfsvisit[node]=0;
  return false;
}
bool DFscycle(int n,vector<int>adj[]){
  vector<int>visit(n);
  vector<int>dfsvisit(n);
  for(int i=0;i<n;i++){
   if(!visit[i]){
       if(chkcycledfs(i,visit,adj,dfsvisit)){
           return true;
       }
   }
  }
  return false;
}
void solve(){
  ll n;
  cin>>n;
  vector<ll>adj[n+1];
  for(ll i=1;i<=n;i++){
    ll x;cin>>x;
    for(ll j=0;j<x;j++){
      
    }
  }
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
