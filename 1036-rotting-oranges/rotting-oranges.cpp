class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j]=1;
                }
            }
        }
        vector<int> drow={0,0,-1,1};
        vector<int> dcol={-1,1,0,0};
        int count = 0;
        while (!q.empty()) {
            int len = q.size();
            int flag = 0;
            for (int i = 0; i < len; i++) {
                int cr = q.front().first;
                int cc = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int newr = cr + drow[k];
                    int newc = cc + dcol[k];

                    if (newr >= 0 && newr < n && newc >= 0 && newc < m &&
                        grid[newr][newc] == 1 && visited[newr][newc] == 0) {
                        visited[newr][newc] = 1;
                        grid[newr][newc]=2;
                        flag=1;
                        q.push({newr, newc});
                    }
                }
            }
            if(flag) count++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return count;
    }
};