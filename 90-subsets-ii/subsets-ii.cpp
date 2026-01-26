class Solution {
public:
    void helper(int i,vector<int>&nums,vector<vector<int>>&ans,vector<int>&curr){
        if(i>nums.size()) return;
        if(curr.size()<=nums.size()){
            ans.push_back(curr);
        }
        for (int j = i; j < nums.size(); j++) {
            // Skip duplicates
            if (j > i && nums[j] == nums[j - 1])
                continue;

            curr.push_back(nums[j]);
            helper(j + 1, nums, ans, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>>ans;
        vector<int>curr;
        helper(0,nums,ans,curr);
        return ans;
    }
};