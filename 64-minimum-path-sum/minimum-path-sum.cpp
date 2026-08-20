class Solution {
public:
    int fun(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i>=n || j>=m) return INT_MAX;
        if(i==n-1 && j==m-1) return grid[n-1][m-1];
        if(dp[i][j]!=-1) return dp[i][j];
        int down=fun(i+1,j,grid,dp);
        int right=fun(i,j+1,grid,dp);
        return dp[i][j]=grid[i][j]+min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return fun(0,0,grid,dp);
    }
};