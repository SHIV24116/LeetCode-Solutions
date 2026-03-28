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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        // base case
        if(inorder.size() == 0) return nullptr;

        // root is last element of postorder
        int rootVal = postorder.back();
        TreeNode* root = new TreeNode(rootVal);

        // find root in inorder
        int idx = 0;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == rootVal){
                idx = i;
                break;
            }
        }

        // split inorder
        vector<int> leftIn(inorder.begin(), inorder.begin() + idx);
        vector<int> rightIn(inorder.begin() + idx + 1, inorder.end());

        // split postorder
        vector<int> leftPost(postorder.begin(), postorder.begin() + idx);
        vector<int> rightPost(postorder.begin() + idx, postorder.end() - 1);

        root->left = buildTree(leftIn, leftPost);
        root->right = buildTree(rightIn, rightPost);

        return root;
    }
};