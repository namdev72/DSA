class Solution {
    int time = 1;

public:

    void df(int node, int parent,
            vector<int>& low,
            vector<int>& tin,
            vector<int>& visited,
            vector<vector<int>>& ans,
            vector<vector<int>>& adj) {

        visited[node] = 1;

        tin[node] = low[node] = time++;

        for (auto it : adj[node]) {

            // Don't go back through the same edge
            if (it == parent)
                continue;

            // Tree edge
            if (visited[it] == 0) {

                df(it, node, low, tin,
                   visited, ans, adj);

                // Update low-link value
                low[node] = min(low[node], low[it]);

                // Bridge condition
                if (low[it] > tin[node]) {
                    ans.push_back({node, it});
                }
            }

            // Back edge
            else {
                low[node] = min(low[node], tin[it]);
            }
        }
    }


    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);

        // Build adjacency list
        for (auto it : connections) {

            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> low(n);
        vector<int> tin(n);
        vector<int> visited(n, 0);

        vector<vector<int>> ans;

        // Handle disconnected graph
        for (int i = 0; i < n; i++) {

            if (visited[i] == 0) {

                df(i, -1, low, tin,
                   visited, ans, adj);
            }
        }

        return ans;
    }
};