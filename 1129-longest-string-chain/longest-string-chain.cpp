class Solution {
public:
    bool cmp(string s1,string s2)
    {
        if(s1.size()!=s2.size()+1) return false;
        int i=0;
        int j=0;
        while(i<s1.size())
        {
            if(s1[i]==s2[j])
            {
                i++;
                j++;
            }else{
                i++;
            }
        }
        if(i==s1.size() && j==s2.size()) return true;
        return false;
    }

    static bool comp(string &s1,string &s2)
    {
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),comp);
        int maxlen=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(cmp(words[i],words[j]) && dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                }
            }
            if(dp[i]>maxlen)
            {
                maxlen=dp[i];
            }
        }
        return maxlen;
    }
};