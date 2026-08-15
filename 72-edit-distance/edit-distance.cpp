class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // dp[i][j] = minimum operations to convert first i characters of word1 into first j characters of word2
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        // Convert first i characters of word1 into an empty string -> i deletions
        for (int i = 0; i <= n; i++) dp[i][0] = i;
        // Convert empty string into first j characters of word2 -> j insertions
        for (int j = 0; j <= m; j++) dp[0][j] = j;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],     // Delete
                        dp[i][j - 1],     // Insert
                        dp[i - 1][j - 1]  // Replace
                    });
                }
            }
        }
        return dp[n][m];
    }
};