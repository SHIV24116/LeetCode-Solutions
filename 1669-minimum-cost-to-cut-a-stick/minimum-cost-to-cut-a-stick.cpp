class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // Add the two boundaries ......end points of the stick
        cuts.push_back(0);
        cuts.push_back(n);
        // Sort all positions
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        // dp[i][j] = minimum cost to perform all cuts between cuts[i] and cuts[j]
        vector<vector<int>> dp(m, vector<int>(m, 0));

        // Length of interval in terms of indices
        for (int len=2;len<m;len++){
            for (int i=0;i + len < m;i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                // Try every cut between i and j
                for (int k = i + 1; k < j; k++) {
                    int cost =dp[i][k]+ dp[k][j]+ (cuts[j] - cuts[i]);
                    dp[i][j] = min(dp[i][j],cost);
                }
            }
        }
        return dp[0][m-1];
    }
};