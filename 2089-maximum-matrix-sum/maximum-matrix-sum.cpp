class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int neg = 0;
        int sm = INT_MAX;
        for (auto& row : matrix) {
            for (int x : row) {
                if (x < 0) neg++;
                sum += abs(x);
                sm = min(sm, abs(x));
            }
        }
        return (neg % 2 == 0) ? sum : sum - 2LL * sm;
    }
};
