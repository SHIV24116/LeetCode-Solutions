class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int s=0;
        int l=0;
        for(int r=0;r<nums.size();r++){
            s+=nums[r];
            if(s>=target){
                while(l<=r && s>=target){
                    ans=min(ans,r-l+1);
                    s-=nums[l];
                    l++;
                }
             }
             
        }
        if(ans==INT_MAX) return 0;
        return ans;

    }
};