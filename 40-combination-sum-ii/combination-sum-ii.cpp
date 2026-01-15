class Solution {
public:
    void helper(int i,vector<int>&candidates,int target,vector<vector<int>>&ans,vector<int>&curr){
        if(target==0){
            ans.push_back(curr);
        }
        for (int j = i; j < candidates.size(); j++) {
            // Skip duplicates
            if (j > i && candidates[j] == candidates[j - 1])
                continue;

            if (candidates[j] > target)
                break;

            curr.push_back(candidates[j]);
            helper(j + 1, candidates, target - candidates[j], ans, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // REQUIRED
        vector<vector<int>>ans;
        vector<int>curr;
        helper(0,candidates,target,ans,curr);
        return ans;
    }
};