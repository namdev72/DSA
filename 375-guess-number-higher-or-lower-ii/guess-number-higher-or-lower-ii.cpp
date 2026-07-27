class Solution {
public:
    int fun(int s, int e, vector<vector<int>>& dp)
    {
        if(s >= e) return 0;

        if(dp[s][e] != -1)
            return dp[s][e];

        int ans = INT_MAX;

        for(int i = s; i <= e; i++)
        {
            int left  = fun(s, i - 1, dp);
            int right = fun(i + 1, e, dp);

            ans = min(ans, i + max(left, right));
        }

        return dp[s][e] = ans;
    }

    int getMoneyAmount(int n)
    {
        vector<vector<int>> dp(n + 2,
                               vector<int>(n + 2, -1));

        return fun(1, n, dp);
    }
};