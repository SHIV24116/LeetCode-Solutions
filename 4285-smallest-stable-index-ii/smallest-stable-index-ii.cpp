class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>v(nums.size());
        int x=INT_MAX;
        for(int i=n-1;i>=0;i--){
            x=min(x,nums[i]);
            v[i]=x;
        }
        int y=INT_MIN;
        for(int i=0;i<nums.size();i++){
            y=max(y,nums[i]);
            if(y-v[i]<=k) return i;
        }
        return -1;
        
    }
};