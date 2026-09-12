class Disjoint{
    vector<int> parent,size;
    public:
    Disjoint(int n)
    {
        parent.resize(n+1,1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findparent(int node)
    {
        if(parent[node]==node) return node;
        return parent[node]=findparent(parent[node]);
    }

    void unionbysize(int u,int v)
    {
        int pu=findparent(u);
        int pv=findparent(v);
        if(pu==pv) return ;
        if(size[pu]<size[pv])
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        Disjoint ds(n);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mp.find(mail)==mp.end()) mp[mail]=i;
                else ds.unionbysize(i,mp[mail]);
            }
        }

        vector<vector<string>> mergedmail(n);
        for(auto it:mp)
        {
            string mail=it.first;
            int node=ds.findparent(it.second);
            mergedmail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            if(mergedmail[i].size()==0) continue;
            vector<string> temp;
            sort(mergedmail[i].begin(),mergedmail[i].end());
            temp.push_back(accounts[i][0]);
            for(auto it:mergedmail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;

    }
};