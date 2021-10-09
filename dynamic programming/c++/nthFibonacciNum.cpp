#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    vector<ll>dp(n+1,0);            // Initializing dp vector which will store the ith fibnoacci number at ith index
    dp[2] = 1;                      // Defining base case

    for(int i = 3 ; i <= n ; i++){
        dp[i] = dp[i-1] + dp[i-2];  // Using previous results to obtain the next 
    }
    cout<<"Finonacci Number : "<<dp[n];     // Printing the nth fibnonacci number
return 0;
}