class Solution {
public:
    int fun(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& dp)
    {
        int m=mat.size();
        int n=mat[0].size();
        if (i >= m || j >= n)
            return 0;
        if(mat[i][j]==1) return 0;
        if (i == m-1 && j == n-1)
            return 1;
        
        //if(mat[i][j]==1) return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        
        int down = fun(i + 1, j,mat, dp);
        int right = fun(i, j + 1, mat, dp);

        return dp[i][j] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return fun(0,0,obstacleGrid,dp);
    }
};