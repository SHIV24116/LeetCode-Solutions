class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> prev(amount + 1, INT_MAX);
        prev[0] = 0;

        for (int i = 0; i < coins.size(); i++) {
            vector<int> curr(amount + 1, INT_MAX);
            //curr[x]=minimum coins needed to make amount x
            //curr[x]=INT_MAX...............x is impossible to make from any combi. of coins
            curr[0] = 0;
            for (int j = 1; j <= amount; j++) {
                int nottake = prev[j];
                int take = INT_MAX;
                if(coins[i]<=j && curr[j-coins[i]]!=INT_MAX) take=curr[j-coins[i]]+1; //can use same coin again so use curr instead of prev here
                curr[j] = min(take, nottake);
            }
            prev = curr;
        }
        return (prev[amount] == INT_MAX) ? -1 : prev[amount];
    }
};
