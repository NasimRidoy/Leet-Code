class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=prices[0], profit=0;
        for(int i=1;i<prices.size();i++)
        {
            profit = max(prices[i]-mn, profit);
            mn = min(mn, prices[i]);
        }
        return profit;
    }
};