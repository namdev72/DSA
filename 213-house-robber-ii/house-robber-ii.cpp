class Solution {
public:
int fun(vector<int>& nums,int idx,vector<int>& dp,int e){
        if(idx==e) return nums[e];
        if(idx>e) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int include=nums[idx]+fun(nums,idx+2,dp,e);
        int exclude=0+fun(nums,idx+1,dp,e);
        return dp[idx]=max(include,exclude);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
         if(n == 1)
            return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        return max(fun(nums,0,dp1,n-2),fun(nums,1,dp2,n-1));
    }
};