class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int n = nums.size();

        int total = 0;
        for(int x : nums)
            total += x;

        if(total % 2 != 0)
            return false;

        int target = total / 2;

        vector<vector<bool>> dp(n,
                                vector<bool>(target + 1, false));

        // Base Case 1
        for(int i = 0; i < n; i++)
            dp[i][0] = true;

        // Base Case 2
        if(nums[0] <= target)
            dp[0][nums[0]] = true;

        for(int index = 1; index < n; index++)
        {
            for(int t = 1; t <= target; t++)
            {
                bool notTake = dp[index - 1][t];

                bool take = false;
                if(nums[index] <= t)
                    take = dp[index - 1][t - nums[index]];

                dp[index][t] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }
};