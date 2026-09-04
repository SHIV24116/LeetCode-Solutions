class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>v(n);
        int x=INT_MAX;
        for(int i=n-1;i>=0;i--){
            v[i]=min(x,nums[i]);
            x=v[i];
        }
        int y=INT_MIN;
        for(int i=0;i<n;i++){
            int z=max(y,nums[i]);
            y=z;
            if(z-v[i]<=k) return i;
        }
        return -1;
    }
};