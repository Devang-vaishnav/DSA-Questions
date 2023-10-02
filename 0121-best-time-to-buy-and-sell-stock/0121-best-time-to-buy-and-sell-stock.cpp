class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mxProfit = 0;
        int mn = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            if(mn > prices[i]){
                mn = prices[i];
            }
            mxProfit = max(mxProfit,prices[i]-mn);
        }
        return mxProfit;
    }
};