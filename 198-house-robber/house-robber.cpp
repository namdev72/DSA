class Solution {
public:
    int fun(vector<int>& nums,int idx,vector<int>& dp){
        if(idx==0) return nums[0];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int include=nums[idx]+fun(nums,idx-2,dp);
        int exclude=0+fun(nums,idx-1,dp);
        return dp[idx]=max(include,exclude);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return fun(nums,n-1,dp);
    }
};