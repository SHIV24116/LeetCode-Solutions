// class Solution {
// public:
//     bool helper(int is,int js,int ms,vector<vector<int>>matrix){
//         int p=1;
//         bool x=true;
//         for(int i=is;i<is+ms;i++){
//             for(int j=js;j<js+ms;j++){
//                 if(matrix[i][j]==0) x=false;
//             }
//         }
//         return x;
//     }
//     int countSquares(vector<vector<int>>& matrix) {
//         int m=matrix.size();
//         int n=matrix[0].size();
//         int ct=0;
//         int ms=1;
//         while(ms<=min(m,n)){
//             for(int i=0;i<m-ms+1;i++){
//                 for(int j=0;j<n-ms+1;j++){
//                    if(helper(i,j,ms,matrix)) ct++;
//                 }
//             }
//             ms++;
//         }
//         return ct;
//     }
// };   
/////////this is brute force it gives TLE

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n, 0));
        //dp[iT[j] = largest side length of an all-1 square whose bottom-right corner is (i,j).

        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1) {
                    if(i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                        //min of these guarantees that current cell will too form a square of all 1's.......chooseing min assures that all cells in that area are 1
                    }
                    ans += dp[i][j];
                }
            }
        }
        return ans;
    }
};