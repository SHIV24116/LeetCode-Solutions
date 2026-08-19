class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j==0){//can buy
                    dp[i][j]=max(-prices[i]+dp[i+1][1],dp[i+1][0]);
                }
                if(j==1){ //can sell
                    dp[i][j]=max(prices[i]+dp[i+1][0]-fee,dp[i+1][1]);
                }            
            }
        }     
        return dp[0][0];   
    }
};