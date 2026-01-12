class Solution {
public:
    static const long long MOD = 1000000007;

    int countGoodNumbers(long long n) {
        long long o = n / 2;
        long long e = (n + 1) / 2;
        return (pow(4, o) * pow(5, e)) % MOD;
    }

    long long pow(long long x, long long n) {
        if (n == 0) return 1;
        if (n == 1) return x % MOD;
        if (n % 2 == 1) return (x * pow(x, n - 1)) % MOD;
        return pow((x * x) % MOD, n / 2);
    }
};
