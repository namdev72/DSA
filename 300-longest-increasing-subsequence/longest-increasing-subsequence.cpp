class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
         int n = nums.size();

    vector<vector<int>> dp(
        n+1 ,
        vector<int>(n + 1, 0)
    );

    for (int cur = n - 1; cur >= 0; cur--) {

        for (int prev = cur - 1; prev >= -1; prev--) {

            int notTake = dp[cur+1][prev + 1];

            int take = 0;

            if (prev == -1 || nums[cur] > nums[prev]) {
                take = 1 + dp[cur + 1][cur+1];
            }

            dp[cur][prev + 1] = max(take, notTake);
        }
    }

    return dp[0][0];
    }
};