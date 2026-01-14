class Solution {
public:
    void helper(int ct,vector<int>&v,vector<int>&nums,int n,vector<vector<int>>&ans){
        if(ct==n){
            ans.push_back(v);
            return;
        }
        helper(ct+1,v,nums,n,ans);
        v.push_back(nums[ct]);
        helper(ct+1,v,nums,n,ans);
        v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        vector<vector<int>>ans;
        helper(0,v,nums,nums.size(),ans);
        return ans;
    }
};