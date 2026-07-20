class Solution {
public:
    int rob(vector<int>& nums) {

         // dp[i] stores the max amount looted upto index i
        vector<int>dp(nums.size());

        if(nums.size()==1) return nums[0];
        
        dp[0]=nums[0];
        dp[1]=max(dp[0],nums[1]); //can not choose adjescent elements ...will choose the max we can
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);  //either choose curr or not choose it
        } //can also do it by recursion approach but this is better optimised...O(n)
        // can also do it without using array....just using 2 variables {prev and prev2}
        return dp[nums.size()-1];
        
    }
};