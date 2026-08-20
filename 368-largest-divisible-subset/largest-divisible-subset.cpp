class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1); //dp[i] represents the length of longestDivisible Subset upto index i
        vector<int>prev(n,-1);

        //LIS depends on the original order.
        // a%b==0 or b%a==0.....There is no requirement that their original positions be preserved.
        sort(nums.begin(),nums.end());
        //unsorted DP checks: new element ↔ previous element ....compatible
        //But it needs: new element ↔ EVERY element in previous subset......we require this compatibility
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(dp[j]+1>dp[i] && (nums[i]%nums[j]==0)){  //sorting gives direction to the condition check in sequence
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
        }
        int maxl=0,maxi=0;
        for(int i=0;i<n;i++){
            if(dp[i]>maxl){
                maxl=dp[i];
                maxi=i;
            }
        }
        vector<int>ans;
        while(maxi>=0){
            ans.push_back(nums[maxi]);
            maxi=prev[maxi];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};