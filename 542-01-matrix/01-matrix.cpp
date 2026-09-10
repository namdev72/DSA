class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0));
        vector<vector<int>> ans(n, vector<int>(m,0));

        queue<pair<pair<int,int>,int>> q;

        // Push all 0's into queue
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }

        vector<int> rdelta={-1,0,1,0};
        vector<int> cdelta={0,1,0,-1};

        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            q.pop();

            //ans[r][c]=d;

            for(int k=0;k<4;k++)
            {
                int nr=r+rdelta[k];
                int nc=c+cdelta[k];

                if(nr>=0 && nr<n &&
                   nc>=0 && nc<m &&
                   !visited[nr][nc])
                {
                    visited[nr][nc]=1;
                    q.push({{nr,nc},d+1});
                    ans[nr][nc]=d+1;
                }
            }
        }

        return ans;
    }
};