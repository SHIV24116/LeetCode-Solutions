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
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        traverse(root,inorder);
        int l=0;
        int h=inorder.size()-1;
        while(l<h){
            int s=inorder[l]+inorder[h];
            if(s==k) return true;
            if(s<k) l++;
            else h--;
        }
        return false;
    }
    void traverse(TreeNode* node,vector<int>&inorder){
        if(node==nullptr) return;

        traverse(node->left,inorder);
        inorder.push_back(node->val);
        traverse(node->right,inorder);
    }

    
};