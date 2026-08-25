class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,0);  //dp[i]=maximum sum of first i terms
        for(int i=1;i<=n;i++){
            int mx=0;
            //For index i, try every possible partition starting at i."
            for(int len=1;len<=k && i-len>=0;len++){
                mx=max(mx,arr[i-len]);
                dp[i]=max(dp[i],dp[i-len]+mx*len);
            }
        }
        return dp[n];
        //without dp the partition is not decided globally..a same element may be included in more than one divisions
    }
};