class Solution {
private:
    int func(int m, int n, vector<vector<int>>& dp){
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Base condition
                if (i == 0 && j == 0) {
                   dp[i][j] = 1;
                    /* Skip the rest of the loop and continue with the next iteration.*/
                   continue; 
                }
                /* Initialize variables to store the number of ways from cell above (up) and left (left)*/
                int up = 0;
                int left = 0;
                if (i > 0) up = dp[i - 1][j];
                if (j > 0) left = dp[i][j - 1];
                
                /* Calculate the number of ways to reach the current cell by adding 'up' and 'left'.*/
                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        //Return the total count(0 based indexing)
        return func(m, n, dp);
    }
};