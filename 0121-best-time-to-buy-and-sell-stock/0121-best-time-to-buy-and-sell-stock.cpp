class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mxProfit = 0;
        int buyPrice = prices[0];

        for(int i = 1; i < n; i++){
            int diff = prices[i] - buyPrice;
            mxProfit = max(mxProfit,diff);
            buyPrice = min(buyPrice,prices[i]);
        }
        return mxProfit;
    }
};