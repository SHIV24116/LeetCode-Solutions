class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l=0;
        int o=0;
        int ans=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]%2!=0) o++;
            while(o>k){
                if(nums[l]%2==1) o--;
                l++;
            }
            if(o==k) ans++;
            if(nums[l]%2==0 && o==k){
                int ct=0;
                for(int j=l;j<=r;j++){
                    if(nums[j]%2==1) break;
                    else ct++;
                }
                ans+=ct;
            }
        }
        return ans;
    }
};