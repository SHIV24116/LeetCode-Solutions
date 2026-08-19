class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(k+1,vector<long long>(2,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=k;j++){
                for(int b=0;b<2;b++){
                    if(b==0){ //can buy
                        dp[i][j][b]=max(-prices[i]+dp[i+1][j][1],0+dp[i+1][j][0]);
                    }
                    if(b==1){ //can sell
                        dp[i][j][b]=max(prices[i]+dp[i+1][j-1][0],0+dp[i+1][j][1]);
                    }
                }
            }
        }
        return dp[0][k][0];
        
    }
};