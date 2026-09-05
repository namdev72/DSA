class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);
        vector<int> count(n, 1);

        int maxLen = 1;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {

                if (nums[j] < nums[i]) {

                    // Found a longer LIS
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }

                    // Found another LIS of same length
                    else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }

            maxLen = max(maxLen, dp[i]);
        }

        int ans = 0;

        // Add counts of all LIS having maximum length
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLen) {
                ans += count[i];
            }
        }

        return ans;
    }
};