class Solution {
public:
    int fun(int idx, int endIndex, vector<int>& slices, int n, vector<vector<int>>& dp) {
        // Base Cases: No more slices needed OR reached the boundary
        if (n == 0 || idx > endIndex) return 0;
        
        // Return cached result if available
        if (dp[idx][n] != -1) return dp[idx][n];
        
        // Option 1: Take current slice -> move to idx+2, need n-1 more
        int take = slices[idx] + fun(idx + 2, endIndex, slices, n - 1, dp);
        
        // Option 2: Skip current slice -> move to idx+1, still need n
        int notake = 0 + fun(idx + 1, endIndex, slices, n, dp);
        
        return dp[idx][n] = max(take, notake); 
    }

    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        int n = k / 3; // Number of slices we need to pick
        
        // Case 1: Consider slices from index 0 to k - 2
        vector<vector<int>> dp1(k, vector<int>(n + 1, -1));
        int case1 = fun(0, k - 2, slices, n, dp1);
        
        // Case 2: Consider slices from index 1 to k - 1
        vector<vector<int>> dp2(k, vector<int>(n + 1, -1));
        int case2 = fun(1, k - 1, slices, n, dp2);
        
        return max(case1, case2);
    }
};