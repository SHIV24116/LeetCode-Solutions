class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> prev(amount + 1, 0);
        prev[0] = 1;

        for (long long i = 0; i < coins.size(); i++) {
            vector<unsigned long long> curr(amount + 1, 0);
            curr[0] = 1;

            for (long long j = 1; j <= amount; j++) {
                unsigned long long nottake = prev[j];
                unsigned long long take = 0;
                if (coins[i] <= j) take = curr[j - coins[i]]; //Every way to make (j - coins[i])  becomes one valid way to make j by appending a coins[i].
                curr[j] = take + nottake;
            }
            prev = curr;
        }
        return (int)prev[amount];
    }
};