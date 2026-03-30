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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return nullptr;
        TreeNode* root=new TreeNode(preorder[0]);
        stack<TreeNode*>st;
        st.push(root);
        for(int i=1;i<preorder.size();i++){
            TreeNode* prev=st.top();
            if(preorder[i]<prev->val){
                prev->left=new TreeNode(preorder[i]);
                st.push(prev->left);
            }
            else{
                st.pop();
                while(!st.empty() && preorder[i]>st.top()->val){
                    prev=st.top();
                    st.pop();
                }
                prev->right=new TreeNode(preorder[i]);
                st.push(prev->right);
            }
        }
        return root;
    }
};