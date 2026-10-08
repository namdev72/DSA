class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        //{{i,j},dist}
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }
        vector<int> drow = {0, 0, -1, 1};
        vector<int> dcol = {-1, 1, 0, 0};
        while (!q.empty()) {
            int cr = q.front().first.first;
            int cc = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int newr = cr + drow[k];
                int newc = cc + dcol[k];

                if (newr >= 0 && newr < n && newc >= 0 && newc < m &&
                    mat[newr][newc] == 1 && visited[newr][newc] == 0) {
                    visited[newr][newc] = 1;
                    ans[newr][newc] = dis + 1;
                    q.push({{newr, newc}, dis + 1});
                }
            }
        }
        return ans;
    }
};