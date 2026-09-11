class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //adj matrix create
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        //dist and quwuw
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,k});
        while(!q.empty())
        {
            int dis=q.top().first;
            int node=q.top().second;
            q.pop();
           // if(dis > dist[node])
             //   continue;
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int cost=it.second;
                if(dis+cost<dist[adjnode])
                {
                    dist[adjnode]=dis+cost;
                    q.push({dist[adjnode],adjnode});
                }
            }
        }
        int maxi = 0;

        for(int i = 1; i <= n; i++)
        {
            if(dist[i] == INT_MAX)
                return -1;

            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }
};