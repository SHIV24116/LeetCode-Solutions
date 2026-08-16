class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,false));
        dp[0][0]=true;
        // Empty s can only be matched by a pattern consisting entirely of '*'
        for (int j = 1; j <= m; j++) {
            dp[0][j]=dp[0][j-1] && (p[j - 1]=='*');
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*') dp[i][j]=dp[i-1][j] || dp[i][j-1];
                // dp[i][j-1]....case when we assume * matches zero chars
                // dp[i-1][j]......case when char i is matched with p[j]...but p[j] can match ore chars so it does not get consumed...now we check for the prev char of s.
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};