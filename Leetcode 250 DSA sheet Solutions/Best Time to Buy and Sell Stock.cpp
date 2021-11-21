class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minm= prices[0],p=0,n = prices.size(),x=0;
        for(int i = 0 ; i < n;i++){
            minm= min(minm,prices[i]);
            x = prices[i] - minm;
            
            p = max(x,p);
        }
        return p;
        
    
    }
};