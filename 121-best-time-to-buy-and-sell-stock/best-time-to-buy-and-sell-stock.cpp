class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        int buy=prices[0];
        for(int i=0;i<n;i++)
        {
            profit=max(profit,prices[i]-buy);
            buy=min(buy,prices[i]);
        }
        return profit;
    }
};