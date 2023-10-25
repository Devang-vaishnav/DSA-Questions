class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int mnPrices = prices[0];
        for(int i = 1; i < n; i++){
            ans = max(ans,prices[i]-mnPrices);
            mnPrices = min(mnPrices,prices[i]);
        }
        return ans;
    }
};