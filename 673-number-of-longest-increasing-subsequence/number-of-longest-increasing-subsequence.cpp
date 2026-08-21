class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n,1);  //no. of longest subsequences ending at index i
        vector<int>dp2(n,1); //length of longest increasing subsequence ending at index i
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    // Found a longer subsequence ending at i
                    if(dp2[j]+1>dp2[i]){
                        dp2[i]=dp2[j]+1;
                        dp1[i]=dp1[j];
                    }
                    // Found another subsequence of same maximum length
                    else if(dp2[i]==dp2[j]+1) dp1[i]+=dp1[j];
                }
            }
        } 
        int mx = *max_element(dp2.begin(),dp2.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if(dp2[i] == mx){
                ans += dp1[i];
            }
        }
        return ans;
    }
};