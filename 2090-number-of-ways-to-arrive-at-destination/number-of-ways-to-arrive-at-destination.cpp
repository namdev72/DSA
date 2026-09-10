class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        // Adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for(auto& it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Minimum distance
        vector<long long> dist(n, LLONG_MAX);

        // Number of shortest paths
        vector<int> way(n, 0);

        // {distance, node}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > q;

        int MOD = 1e9 + 7;

        dist[0] = 0;
        way[0] = 1;

        q.push({0, 0});

        while(!q.empty())
        {
            long long cos = q.top().first;
            int node = q.top().second;

            q.pop();

            // Ignore outdated entry
            if(cos > dist[node])
                continue;

            for(auto el : adj[node])
            {
                int adjnode = el.first;
                int wt = el.second;

                long long newDist = cos + wt;

                // Found a shorter path
                if(newDist < dist[adjnode])
                {
                    dist[adjnode] = newDist;

                    way[adjnode] = way[node];

                    q.push({newDist, adjnode});
                }

                // Found another shortest path
                else if(newDist == dist[adjnode])
                {
                    way[adjnode] =
                        (way[adjnode] + way[node]) % MOD;
                }
            }
        }

        return way[n - 1];
    }
};