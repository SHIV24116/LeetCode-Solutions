class Solution {
public:
    int minInsertions(string s) {
        // we just need to findout the longest possible pallindromic subsequence = k
        // then we just need to insert (n-k) characters
        string s1=s;
        int n=s.size();
        reverse(s1.begin(),s1.end());
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,0));
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=s.size();j++){
                if(s1[j-1]==s[i-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int k= dp[n][n];
        return n-k;
    }
};