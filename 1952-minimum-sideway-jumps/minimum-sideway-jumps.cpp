class Solution {
public:
    int fun(vector<int>& ob,int currlan,int currpos,vector<vector<int>>& dp)
    {
        int n=ob.size();

        if(currpos==n-1)
            return 0;

        if(dp[currlan][currpos]!=-1)
            return dp[currlan][currpos];

        if(ob[currpos+1]!=currlan)
            return dp[currlan][currpos]=fun(ob,currlan,currpos+1,dp);

        int ans=INT_MAX;

        for(int i=1;i<=3;i++)
        {
            if(i!=currlan && ob[currpos]!=i)
            {
                ans=min(ans,1+fun(ob,i,currpos,dp));
            }
        }

        return dp[currlan][currpos]=ans;
    }

    int minSideJumps(vector<int>& obstacles)
    {
        int n=obstacles.size();

        vector<vector<int>> dp(4,vector<int>(n,-1));

        return fun(obstacles,2,0,dp);
    }
};