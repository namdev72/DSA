class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        map<char,int> mpp;
        int n=s.length();
        int ans=0;
        while(r<n)
        {
            if(mpp.find(s[r])!=mpp.end())
            {
                int len=mpp.size();
                ans=max(ans,len);
                while(s[l]!=s[r])
                {
                    mpp.erase(s[l]);
                    l++;
                }
                l++;
            }
            mpp[s[r]]++;
            r++;
        }
        int len=mpp.size();
        ans=max(ans,len);
        return ans;
        
    }
};