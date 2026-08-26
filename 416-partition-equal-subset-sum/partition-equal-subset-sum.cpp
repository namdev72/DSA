class Solution {
public:

    bool fun(int n, vector<int>& nums, int sum)
    {
        // dp[i][j] =
        // Can we make sum j using first i elements?

        vector<vector<bool>> dp(
            n + 1,
            vector<bool>(sum + 1, false)
        );

        // Sum 0 can always be made
        // by taking nothing
        for(int i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                // Not take
                bool notake = dp[i - 1][j];

                // Take
                bool take = false;

                if(nums[i - 1] <= j)
                {
                    take = dp[i - 1][j - nums[i - 1]];
                }

                dp[i][j] = notake || take;
            }
        }

        return dp[n][sum];
    }

    bool canPartition(vector<int>& nums)
    {
        int n = nums.size();

        int total = 0;

        for(int x : nums)
        {
            total += x;
        }

        // Odd sum cannot be divided equally
        if(total % 2 != 0)
            return false;

        int sum = total / 2;

        return fun(n, nums, sum);
    }
};