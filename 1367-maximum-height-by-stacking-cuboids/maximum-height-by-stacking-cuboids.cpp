class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        // Step 1: Normalize dimensions for each cuboid (w <= l <= h)
        for (auto& c : cuboids) {
            sort(c.begin(), c.end());
        }
        
        // Step 2: Sort cuboids globally by width, length, then height
        sort(cuboids.begin(), cuboids.end());
        
        int n = cuboids.size();
        vector<int> dp(n);
        int maxTotalHeight = 0;
        
        // Step 3: LIS-style DP
        for (int i = 0; i < n; ++i) {
            dp[i] = cuboids[i][2]; // Base height is its own height
            for (int j = 0; j < i; ++j) {
                // Check if cuboid j can be placed underneath cuboid i
                if (cuboids[j][0] <= cuboids[i][0] && 
                    cuboids[j][1] <= cuboids[i][1] && 
                    cuboids[j][2] <= cuboids[i][2]) {
                    
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
            maxTotalHeight = max(maxTotalHeight, dp[i]);
        }
        
        return maxTotalHeight;
    }
};