class Solution {
public:

    int neededcuts(int i, int j,vector<vector<int>>& dp,vector<vector<bool>>& pal) {
        if(dp[i][j] != INT_MAX) return dp[i][j];
        if(pal[i][j]) return dp[i][j] = 0;
        for(int k = i; k < j; k++) {
            if(pal[i][k]) dp[i][j] = min(dp[i][j],1 + neededcuts(k+1, j, dp, pal));
        }
        return dp[i][j];
    }

    int minCut(string s) {
        int n = s.size();
        // pal[i][j] = whether s[i...j] is palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(s[i]==s[j] && (j-i<=2 || pal[i+1][j-1])) pal[i][j] = true;
            }
        }
        vector<vector<int>> dp(n,vector<int>(n, INT_MAX));
        return neededcuts(0, n-1, dp, pal);
    }
};