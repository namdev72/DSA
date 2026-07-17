class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> d(n, INT_MAX);
        d[src] = 0;

        // {stops, {node, cost}}
        queue<pair<int,pair<int,int>>> q;

        q.push({0,{src,0}});

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            int step = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(step > k)
                continue;

            for(auto i : adj[node])
            {
                int adjnode = i.first;
                int wc = i.second;

                if(cost + wc < d[adjnode] && step <= k)
                {
                    d[adjnode] = cost + wc;

                    q.push({step+1,{adjnode,cost+wc}});
                }
            }
        }

        if(d[dst] == INT_MAX)
            return -1;

        return d[dst];
    }
};