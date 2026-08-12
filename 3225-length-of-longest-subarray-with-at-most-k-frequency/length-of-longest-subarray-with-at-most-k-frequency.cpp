class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0;
        int ans=0;
        unordered_map<int,int>m;
        for(int r=0;r<nums.size();r++){
            m[nums[r]]++;
            if(m[nums[r]]<=k){
                ans=max(ans,r-l+1);
            }
            else{
                while(m[nums[r]]>k && l<=r){
                    m[nums[l]]--;
                    l++;
                }
            }
        }

        return ans;
        
    }
};