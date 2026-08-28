class Solution {
public:
    int minimumDifference(vector<int>& nums) {

        int n = nums.size();
        int half = n / 2;

        int total = 0;
        for (int x : nums)
            total += x;

        // left[i]  = sums of choosing i elements from left half
        // right[i] = sums of choosing i elements from right half
        vector<vector<int>> left(half + 1);
        vector<vector<int>> right(half + 1);

        // Generate all subsets of left and right halves
        for (int mask = 0; mask < (1 << half); mask++) {

            int sumLeft = 0;
            int sumRight = 0;
            int cnt = 0;

            for (int i = 0; i < half; i++) {

                if (mask & (1 << i)) {
                    sumLeft += nums[i];
                    sumRight += nums[i + half];
                    cnt++;
                }
            }

            left[cnt].push_back(sumLeft);
            right[cnt].push_back(sumRight);
        }

        // Sort right side sums for binary search
        for (int i = 0; i <= half; i++) {
            sort(right[i].begin(), right[i].end());
        }

        int ans = INT_MAX;

        // We need to select exactly half elements
        // for the first array.
        //
        // If we select i elements from left half,
        // we need (half - i) elements from right half.

        for (int i = 0; i <= half; i++) {

            int need = half - i;

            for (int sumLeft : left[i]) {

                // We want:
                //
                // S1 = sumLeft + sumRight
                // S2 = total - S1
                //
                // difference = |S1 - S2|
                //
                //             = |2*S1 - total|
                //
                // Ideally:
                //
                // 2*S1 ≈ total
                //
                // so:
                //
                // S1 ≈ total / 2

                double target = (double)total / 2.0;

                auto it = lower_bound(
                    right[need].begin(),
                    right[need].end(),
                    target - sumLeft
                );

                // Candidate 1
                if (it != right[need].end()) {

                    int sumRight = *it;
                    int sum1 = sumLeft + sumRight;

                    ans = min(ans, abs(total - 2 * sum1));
                }

                // Candidate 2
                if (it != right[need].begin()) {

                    --it;

                    int sumRight = *it;
                    int sum1 = sumLeft + sumRight;

                    ans = min(ans, abs(total - 2 * sum1));
                }
            }
        }

        return ans;
    }
};