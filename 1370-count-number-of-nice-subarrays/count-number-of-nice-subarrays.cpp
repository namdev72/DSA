class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        mp[0] = 1;

        int prefix = 0;
        int count = 0;

        for(int x : nums)
        {
            // odd -> 1, even -> 0
            prefix += (x % 2);

            if(mp.find(prefix - k) != mp.end())
            {
                count += mp[prefix - k];
            }

            mp[prefix]++;
        }

        return count;
    }
};