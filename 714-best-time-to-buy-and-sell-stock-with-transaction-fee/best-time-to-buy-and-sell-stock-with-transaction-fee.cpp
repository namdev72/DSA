class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        //int sellcount=0;
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<2;buy++)
            {
                if(buy)
                {
                    dp[idx][buy]=max(-prices[idx]+dp[idx+1][0],dp[idx+1][1]);
                }
                else{
                    //selllcount++;
                    dp[idx][buy]=max(prices[idx]-fee+dp[idx+1][1],dp[idx+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};