class Disjoint {
    vector<int> parent, size;

public:
    Disjoint(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1, 1);

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
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=0;
        int m=0;
        for(auto it:stones){
            n=max(n,it[0]);
            m=max(m,it[1]);
        }
        Disjoint ds(n+m+1);
        set<int> st;
        for(auto it:stones)
        {
            int noderow=it[0];
            int nodecol=it[1]+n+1;
            ds.unionbysize(noderow,nodecol);
            st.insert(noderow);
            st.insert(nodecol);
        }
        int count=0;
        for(auto it:st)
        {
            if(ds.findparent(it)==it)
            {

                count++;
            }
        }

        int stonecount=stones.size();
        return stonecount-count;
    }
};