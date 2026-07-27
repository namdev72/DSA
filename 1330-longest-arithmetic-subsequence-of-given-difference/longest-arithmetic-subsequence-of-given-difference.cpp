class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference)
{
    unordered_map<int,int> dp;
    int ans = 1;

    for(int x : arr)
    {
        int prev = x - difference;

        dp[x] = dp[prev] + 1;

        ans = max(ans, dp[x]);
    }

    return ans;
}
};