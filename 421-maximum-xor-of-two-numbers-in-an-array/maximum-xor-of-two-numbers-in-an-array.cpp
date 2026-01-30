class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> prefixes;

        for (int bit = 31; bit >= 0; bit--) {
            prefixes.clear();
            for (int num : nums) {
                prefixes.insert(num >> bit);
            }

            int want = (ans << 1) | 1;

            for (int p : prefixes) {
                if (prefixes.count(p ^ want)) {
                    ans = want;
                    break;
                }
            }

            if (ans != want) {
                ans = ans << 1;
            }
        }
        return ans;
    }
};
