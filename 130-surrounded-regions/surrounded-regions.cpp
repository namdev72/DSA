class Solution {
public:
    void bfs(queue<pair<int,int>>& q,vector<vector<bool>>& visited,vector<vector<char>>& board)
    {
        int n=board.size();
        int m=board[0].size();
        vector<int> rdelta={-1,0,1,0};
        vector<int> cdelta={0,1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=r+rdelta[i];
                int nc=c+cdelta[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && board[nr][nc]=='O')
                {
                    visited[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        //top
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O')
            {
                q.push({0,j});
                visited[0][j]=true;
            }
        }
        //right
        for(int i=0;i<n;i++)
        {
            if(board[i][m-1]=='O')
            {
                q.push({i,m-1});
                visited[i][m-1]=true;
            }
        }
        //bottom
        for(int i=0;i<m;i++)
        {
            if(board[n-1][i]=='O')
            {
                q.push({n-1,i});
                visited[n-1][i]=true;
            }
        }
        //left
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            {
                q.push({i,0});
                visited[i][0]=true;
            }
        }
        bfs(q,visited,board);
        //vecor<vector<char>> ans=board;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j])
                {
                    board[i][j]='X';
                }
            }
        }
    }
};
