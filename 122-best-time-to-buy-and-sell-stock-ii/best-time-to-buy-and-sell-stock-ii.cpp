// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         int buy=prices[0];
//         int ans=0;
//         for(int s=1;s<n;s++)
//         {
//             if((prices[s]-buy)>0)
//             {
//                 ans+=prices[s]-buy;
//                 buy=prices[s];
//                 continue;
//             }
//             buy=min(buy,prices[s]);
//         }

//         int mini=prices[0];
//         int prof=0;
//         for(int i=1;i<prices.size();i++)
//         {
//             prof=max(prof,prices[i]-mini);
//             mini=min(mini,prices[i]);
//         }
//         return prof>ans?prof:ans;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;

        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] > prices[i-1])
                ans += prices[i] - prices[i-1];
        }

        return ans;
    }
};