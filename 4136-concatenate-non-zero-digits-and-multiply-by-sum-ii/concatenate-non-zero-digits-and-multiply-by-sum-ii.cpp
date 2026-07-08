class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;
        int n = s.size();
        vector<long long> preNum(n);
        vector<long long> preSum(n);
        vector<int> cnt(n);
        vector<long long> pow10(n + 1);

        pow10[0] = 1;
        for (int i = 1; i <= n; i++) pow10[i] = (pow10[i - 1] * 10) % MOD;
        long long num = 0;
        long long sum = 0;
        int nz = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum + (s[i] - '0')) % MOD;
            preSum[i] = sum;
            if (s[i] != '0') {
                num = (num*10 + (s[i] - '0')) % MOD;
                nz++;
            }
            preNum[i] = num;
            cnt[i] = nz;
        }
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            long long digitSum = preSum[r];
            if (l) digitSum = (digitSum - preSum[l - 1] + MOD) % MOD;
            int len = cnt[r] - (l ? cnt[l - 1] : 0);
            if (len == 0) {
                ans.push_back(0);
                continue;
            }
            long long x = preNum[r];
            if (l) {
                x = (x - preNum[l - 1] * pow10[len] % MOD + MOD) % MOD;
            }
            ans.push_back((x * digitSum) % MOD);
        }
        return ans;
    }
};