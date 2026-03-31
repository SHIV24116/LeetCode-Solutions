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
    void recoverTree(TreeNode* root) {
        vector<pair<int,TreeNode*>>v;
        io(root,v);
        vector<pair<int,TreeNode*>>w=v;
        sort(w.begin(),w.end());
        pair<int,TreeNode*>p;
        for(int i=0;i<v.size();i++){
            if(v[i].first!=w[i].first){
                TreeNode* n1=v[i].second;
                TreeNode* n2=w[i].second;
                n1->val=w[i].first;
                n2->val=v[i].first;
                break;
            }
        }

        
    }
    void io(TreeNode* node,vector<pair<int,TreeNode*>>&v){
        if(node==nullptr) return;
        io(node->left,v);
        v.push_back({node->val,node});
        io(node->right,v);
    }
};