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
    int countNodes(TreeNode* root) {
        vector<int>v;
        if(root==nullptr) return v.size();
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* n=q.front();
                v.push_back(n->val);
                q.pop();

                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
        }
        return v.size();
        
    }
};