class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1),parent(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        sort(nums.begin(),nums.end());
        int maxlen=0;
        int lastmaxindex=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
            if(dp[i]>maxlen)
            {
                maxlen=dp[i];
                lastmaxindex=i;
            }
        }
        vector<int> ans;
        while(parent[lastmaxindex]!=lastmaxindex)
        {
            ans.push_back(nums[lastmaxindex]);
            lastmaxindex=parent[lastmaxindex];
        }
        ans.push_back(nums[ lastmaxindex]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};