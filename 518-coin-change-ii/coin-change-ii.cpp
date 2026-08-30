class Solution {
public:
    int fun(int amount, vector<int>& coins,int idx, vector<vector<int>>& dp)
    {
        if(idx==0)
        {
            if(amount%coins[0]==0) return 1;
            else return 0; 
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        //not take
        int notake=fun(amount,coins,idx-1,dp);
        //take
        int take=0;
        if(coins[idx]<=amount)
        {
            take=fun(amount-coins[idx],coins,idx,dp);
        }
        return dp[idx][amount]=take+notake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return fun(amount,coins,n-1,dp);
    }
};