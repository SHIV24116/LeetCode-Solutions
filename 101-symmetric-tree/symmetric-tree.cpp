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
    vector<vector<int>> bft(TreeNode* root, bool x){
        vector<vector<int>> v;
        if(root == nullptr) return v;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> l(n);

            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
 
                if(node == nullptr){
                    if(x) l[i] = INT_MIN;
                    else l[n-1-i] = INT_MIN;
                    continue;
                }

                if(x) l[i] = node->val;
                else l[n-1-i] = node->val;

                q.push(node->left);
                q.push(node->right);
            }
            v.push_back(l);
        }
        return v;
    }
    bool isSymmetric(TreeNode* root) {
        if(bft(root->left,true)==bft(root->right,false)) return true;
        return false;
    }
};