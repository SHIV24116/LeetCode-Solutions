class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ms = 0;
        for (int x : nums) ms += x;
        // target must lie in [-ms, ms]
        if (abs(target) > ms) return 0;
        // P = sum of numbers assigned '+'
        // 2P - ms = target
        // P = (target + ms) / 2
        if ((target + ms) % 2 != 0) return 0;
        int P = (target + ms) / 2;

        vector<int> prev(P + 1, 0);
        prev[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> curr(P + 1, 0);
            for (int t = 0; t <= P; t++) {
                // Don't take nums[i]
                curr[t] = prev[t];
                // Take nums[i]
                if (nums[i] <= t) curr[t] += prev[t - nums[i]];
            }
            prev = curr;
        }
        return prev[P];
    }
};