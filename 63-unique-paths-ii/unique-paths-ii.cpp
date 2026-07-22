class Solution {
public:
    int solve(int x,int y,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
        if(x<0 || y<0 || obstacleGrid[x][y]==1) return 0;

        if(x==0 && y==0) return 1;
        if(dp[x][y]!=-1) return dp[x][y];
        
        return dp[x][y]=solve(x-1,y,obstacleGrid,dp) + solve(x,y-1,obstacleGrid,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));


        return solve(m-1,n-1,obstacleGrid,dp);
    }
};