// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete at most two transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
  
//   Example 1:

// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

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
