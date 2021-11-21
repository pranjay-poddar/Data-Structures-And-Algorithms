class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p = 0,n = prices.size(),mn=prices[0],x = 0,sum = 0;
        
        for(int i = 0; i < n;i++){
            mn = min(mn,prices[i]);
            x = prices[i] - mn;
            if(x>0){
                sum+=x;
                mn = prices[i];
            }
            
        }
        return sum;
    }
};