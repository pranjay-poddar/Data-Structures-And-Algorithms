#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    vector<ll>dp(n+1,0);
    dp[2] = 1;

    for(int i = 3 ; i <= n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<"Finonacci Number : "<<dp[n];
return 0;
}