class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // Add boundary balloons
        vector<int> arr(n + 2);
        arr[0] = 1;
        arr[n + 1] = 1;
        for(int i = 0; i < n; i++) {
            arr[i + 1] = nums[i];
        }
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        // dp[i][j] = max coins earned by bursting balloons i to j

        for(int l = 0; l < n; l++) {
            for(int i = 1; i + l <= n; i++) {
                int j = i + l;
                for(int k = i; k <= j; k++) {
                    int cost = arr[i - 1] * arr[k] * arr[j + 1];
                    int prec = dp[i][k - 1];
                    int succ = dp[k + 1][j];
                    int earned = prec + succ + cost;
                    dp[i][j] = max(dp[i][j], earned);
                }
            }
        }
        return dp[1][n];

        //here we assume the k to be the last balloon burst in (i,j).....
        //k-1 and k+1 are the original neighbors of k....so if we assume k as the first burst...then we dont reliably know its neighbours....k-1 and k+1 might already have been blown away; 
        //i-1 and j+1 are the neighbors of k when k is burst last in the interval [i,j].
    }
};