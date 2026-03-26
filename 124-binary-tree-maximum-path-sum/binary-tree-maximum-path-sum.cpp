/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxs=INT_MIN;
        dfs(root,maxs);
        return maxs;

    }
    int dfs(TreeNode* root,int &maxs){
        if(root==nullptr) return 0;

        int leftsum=max(0,dfs(root->left,maxs));
        int rightsum=max(0,dfs(root->right,maxs));

        maxs=max(maxs,root->val+ leftsum + rightsum);

        return max(leftsum,rightsum)+root->val;

    }
};