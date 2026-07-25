class Solution {
public:
    int fun(vector<int>& num1, vector<int>& num2, int idx, int swaped, vector<vector<int>>& dp) {
        // Base case: processed all elements
        if (idx == num1.size()) return 0;
        
        // Step 1: Check cache
        if (dp[idx][swaped] != -1) return dp[idx][swaped];

        int ans = INT_MAX;
        int prev1 = num1[idx - 1];
        int prev2 = num2[idx - 1];

        // If previous step was swapped, swap prev1 and prev2 to reflect actual values
        if (swaped) {
            swap(prev1, prev2);
        }

        // Choice 1: No Swap at current index
        if (num1[idx] > prev1 && num2[idx] > prev2) {
            ans = min(ans, fun(num1, num2, idx + 1, 0, dp));
        }

        // Choice 2: Swap at current index
        if (num1[idx] > prev2 && num2[idx] > prev1) {
            ans = min(ans, 1 + fun(num1, num2, idx + 1, 1, dp));
        }

        return dp[idx][swaped] = ans;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // Dummy element at start so idx = 1 can safely check idx - 1
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        
        int n = nums1.size();
        // dp table of size [n][2] initialized to -1
        vector<vector<int>> dp(n, vector<int>(2, -1));

        // Start from index 1 (since index 0 is our dummy -1)
        return fun(nums1, nums2, 1, 0, dp);
    }
};