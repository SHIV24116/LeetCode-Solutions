class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0;
        int l=0;
        int sum=0;
        for(int r=0;r<nums.size();r++){
            sum=sum+nums[r];
            while(sum>goal && l<r){
                if(nums[l]==1) sum--;
                l++;
            }
            if(sum==goal) ans++; 
            int x=l;
            while(x<r){
                if(sum-nums[x]==goal){
                    x++;
                    ans++;
                }
                else break;
            }
        }
        return ans;
    }
};