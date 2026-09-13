class Disjoint {
    vector<int> parent, size;

public:
    Disjoint(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findparent(int i) {
        if (parent[i] == i)
            return i;

        return parent[i] = findparent(parent[i]);
    }

    void unionbysize(int u, int v) {

        int up_u = findparent(u);
        int up_v = findparent(v);

        if (up_u == up_v)
            return;

        if (size[up_u] < size[up_v]) {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }

    int getsize(int node) {
        return size[findparent(node)];
    }
};


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        Disjoint ds(n * m);

        vector<int> dr = {0, 0, -1, 1};
        vector<int> dc = {-1, 1, 0, 0};


        // STEP 1: Connect all existing land cells
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 0)
                    continue;

                int node = i * m + j;

                for (int k = 0; k < 4; k++) {

                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < m &&
                        grid[nr][nc] == 1) {

                        int adjnode = nr * m + nc;

                        ds.unionbysize(node, adjnode);
                    }
                }
            }
        }


        int maxi = 0;


        // STEP 2: Try converting every 0 into 1
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1)
                    continue;

                set<int> st;

                for (int k = 0; k < 4; k++) {

                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < m &&
                        grid[nr][nc] == 1) {

                        int adjnode = nr * m + nc;

                        st.insert(ds.findparent(adjnode));
                    }
                }


                // Flipped 0 itself
                int sum = 1;

                // Add unique neighbouring components
                for (auto it : st) {
                    sum += ds.getsize(it);
                }

                maxi = max(maxi, sum);
            }
        }


        // STEP 3: If grid is already all 1s
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) {

                    int node = i * m + j;

                    maxi = max(maxi, ds.getsize(node));
                }
            }
        }

        return maxi;
    }
};