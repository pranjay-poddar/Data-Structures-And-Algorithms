/*Best Time to Buy and Sell Stock III
At every instant (or index i of the array), one of the 4 events can happen. 
We can use the following 4 variables to denote these:

firstBuy = price of 1st buy

secondBuy = price of 2nd buy

firstProfit = Profit after selling the first share

secondProfit = profit after selling the second share

Clearly we want to minimise the buying prices and maximise the profit at each and
 every price instant (for each element of array)*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int firstBuy = INT_MAX;
		int secondBuy = INT_MAX;

		int firstProfit = INT_MIN;
		int secondProfit = INT_MIN;

		for(int i=0;i<prices.size();i++){
			// Minimize the first buy price
			firstBuy = min(firstBuy, prices[i]);
			// Maximise the profit when we sell at prices[i]. (Selling price - buying price = profit)
			firstProfit = max(firstProfit, prices[i]-firstBuy);
			// Now minimize the second buy price to see if buying at prices[i] price is minimum.
			// prices[i]-firstProfit is the net expense in buying it.
			secondBuy = min(secondBuy, prices[i]-firstProfit);
			// Now maximise the final profit after selling both shares.
			secondProfit = max(secondProfit, prices[i]-secondBuy);
		}

		return secondProfit;
	}
};