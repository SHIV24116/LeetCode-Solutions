class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int sum=0;
        int n=nums.size();
        vector<int>a(n);
        for(int i=0;i<n;i++){
            sum = sum+nums[i];
            a[i]=sum;
        }
        int min_prefixsum=0;
        for(int i=0;i<nums.size();i++){
            ans=max(a[i]-min_prefixsum,ans);
            min_prefixsum=min(min_prefixsum,a[i]);
            
        }
        return ans;
        
    }
};