class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.length();
        int m = str2.length();

        // LCS table
        vector<vector<int>> dp(
            n + 1,
            vector<int>(m + 1, 0)
        );

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {

                if (str1[i - 1] == str2[j - 1]) {

                    dp[i][j] =
                        1 + dp[i - 1][j - 1];
                }
                else {

                    dp[i][j] =
                        max(dp[i - 1][j],
                            dp[i][j - 1]);
                }
            }
        }

        // Reconstruct SCS
        int i = n;
        int j = m;

        string ans = "";

        while (i > 0 && j > 0) {

            // Same character
            if (str1[i - 1] == str2[j - 1]) {

                ans += str1[i - 1];

                i--;
                j--;
            }

            // Take from str1
            else if (dp[i - 1][j] > dp[i][j - 1]) {

                ans += str1[i - 1];

                i--;
            }

            // Take from str2
            else {

                ans += str2[j - 1];

                j--;
            }
        }

        // Remaining str1
        while (i > 0) {

            ans += str1[i - 1];

            i--;
        }

        // Remaining str2
        while (j > 0) {

            ans += str2[j - 1];

            j--;
        }

        // We constructed answer backwards
        reverse(ans.begin(), ans.end());

        return ans;
    }
};