class Solution {
public:
    void backtrack(int index, int target,vector<int>& candidates,vector<int>& curr,
                   vector<vector<int>>& ans) {
        // valid combination
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        // invalid state
        if (index == candidates.size() || target < 0)
            return;
        // take current element (can reuse it)
        curr.push_back(candidates[index]);
        backtrack(index, target - candidates[index],candidates, curr, ans);
        curr.pop_back();
        // skip current element
        backtrack(index + 1, target,candidates, curr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        backtrack(0, target, candidates, curr, ans);
        return ans;
    }
};
