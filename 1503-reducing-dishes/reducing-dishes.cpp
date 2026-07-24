class Solution {
public:
    int fun(vector<int>& s,int index,int time,vector<vector<int>>& dp)
    {
        if(index==s.size()) return 0;
        if(dp[index][time]!=-1) return dp[index][time];
        int include=s[index]*time+fun(s,index+1,time+1,dp);
        int exclude=0+fun(s,index+1,time,dp);
        return dp[index][time]=max(include,exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return fun(satisfaction,0,1,dp);
    }
};