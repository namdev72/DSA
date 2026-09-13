class Solution {
public:
    int fun(int idx,int d,vector<int>& jd,vector<vector<int>>& dp)
    {
        if(d==1)
        {
            int maxi=INT_MIN;
            for(int i=idx;i<jd.size();i++) maxi=max(maxi,jd[i]);
            return maxi;
        }
        if(dp[d][idx]!=-1) return dp[d][idx];

        int maxD=jd[idx];
        int finalresult = INT_MAX;
         // Choose where current day ends
        for(int i = idx; i <= jd.size() - d; i++)
        {
            maxD = max(maxD, jd[i]);

            finalresult = min(
                finalresult,
                maxD + fun(i + 1, d - 1, jd,dp)
            );
        }
        return dp[d][idx]=finalresult;
    }
    int minDifficulty(vector<int>& jd, int d) {
        int n=jd.size();
        if(n < d)
            return -1;
        vector<vector<int>> dp(d+1,vector<int>(n,-1));
        return fun(0,d,jd,dp);
    }
};