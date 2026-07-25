class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;
        
        // Custom comparator: Width asc, Height desc if widths match
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        
        vector<int> ans;
        for (const auto& env : envelopes) {
            int h = env[1];
            auto it = lower_bound(ans.begin(), ans.end(), h);
            if (it == ans.end()) {
                ans.push_back(h);
            } else {
                *it = h;
            }
        }
        
        return ans.size();
    }
};