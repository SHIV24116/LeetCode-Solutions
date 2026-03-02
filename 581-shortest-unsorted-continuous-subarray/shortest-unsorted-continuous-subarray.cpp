class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>comp=nums;
        int ans=0;
        int ct=0;
        sort(comp.begin(),comp.end());
        for(int i=0;i<nums.size();i++){
            if(ct!=0) ct++;
            if(nums[i]!=comp[i]){
                if(ct==0) ct++;
                ans=ct;
            }
        }
        return ans;
        
    }
};