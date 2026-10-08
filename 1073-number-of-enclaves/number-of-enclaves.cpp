class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
         vector<vector<int>> visited(n,vector<int>(m,0));
        //top
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1)
            {
                q.push({0,i});
                visited[0][i]=1;
                grid[0][i]=0;
            }
        }
        //down
        for(int i=0;i<n;i++)
        {
            if(grid[i][m-1])
            {
                q.push({i,m-1});
                visited[i][m-1]=1;
                grid[i][m-1]=0;
            }
        }
        //bottom
         for(int i=0;i<m;i++)
        {
            if(grid[n-1][i]==1)
            {
                q.push({n-1,i});
                visited[n-1][i]=1;
                grid[n-1][i]=0;
            }
        }
        //left up
        for(int i=0;i<n;i++)
        {
            if(grid[i][0])
            {
                q.push({i,0});
                visited[i][0]=1;
                grid[i][0]=0;
            }
        }
        int count=0;
        vector<int> drow={-1,1,0,0};
        vector<int> dcol={0,0,-1,1};
       
        while(!q.empty())
        {
            int cr=q.front().first;
            int cc=q.front().second;
            q.pop();
            for(int k = 0; k < 4; k++)
            {
                int newr = cr + drow[k];
                int newc = cc + dcol[k];

                if(newr >= 0 && newr < n &&
                   newc >= 0 && newc < m && grid[newr][newc]==1 && visited[newr][newc]==0)
                {
                    visited[newr][newc] = 1;
                    grid[newr][newc]=0;
                    q.push({newr,newc});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};