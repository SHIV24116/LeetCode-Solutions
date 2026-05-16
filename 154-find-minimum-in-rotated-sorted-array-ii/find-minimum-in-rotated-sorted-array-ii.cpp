class Solution {
public:
    int findMin(vector<int>& nums) {
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int l = 0;
        int h= nums.size() - 1;
        while (l< h) {
            int m = l + (h - l) / 2;
            if (nums[m] > nums[h]) l= m + 1;
            else h = m;
        }
        return nums[l];
    }
};