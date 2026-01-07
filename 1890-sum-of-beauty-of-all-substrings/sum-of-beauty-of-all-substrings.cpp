class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int freq[26] = {0};

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int mx = 0;
                int mn = INT_MAX;
                for (auto it: freq) {
                    if (it > 0) {
                        mx = max(mx, it);
                        mn = min(mn, it);
                    }
                }
                ans += (mx - mn);
            }
        }
        return ans;
    }
};
