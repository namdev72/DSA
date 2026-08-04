class Solution {
public:
    int fun(vector<int>& cost,int i,vector<int>& dp)
    {
        if(i==0) return cost[0];
        if(i==1) return cost[1];
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i]+min(fun(cost,i-1,dp),fun(cost,i-2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return min(fun(cost,n-1,dp),fun(cost,n-2,dp));
    }
};