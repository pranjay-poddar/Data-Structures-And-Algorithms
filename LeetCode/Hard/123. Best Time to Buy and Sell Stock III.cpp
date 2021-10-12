class Solution {
public:
    int maxProfit(vector<int>& p) {
         int n=p.size(),sell=p[n-1],buy=p[0];
        int dp[n];
        //1st transaction 
       for(int i=0;i<n;i++)dp[i]=0;
        for(int i=n-2;i>=0;i--){
            sell=max(sell,p[i]);
            dp[i]=max(dp[i+1],sell-p[i]);
        }
        
        // 2nd transaction
        for(int i=1;i<n;i++){
            buy=min(buy,p[i]);
            dp[i]=max(dp[i-1],dp[i]+(p[i]-buy));
        }
        return dp[n-1];
    }
};
