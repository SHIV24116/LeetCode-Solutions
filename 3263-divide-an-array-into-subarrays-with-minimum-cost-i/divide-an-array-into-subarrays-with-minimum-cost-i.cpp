class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int f=nums[0];
        sort(nums.begin(),nums.end());
        if(f==nums[0] || f==nums[1] || f==nums[2]) return (nums[0]+nums[1]+nums[2]);
        else return nums[0]+nums[1]+f;
        
    }
};