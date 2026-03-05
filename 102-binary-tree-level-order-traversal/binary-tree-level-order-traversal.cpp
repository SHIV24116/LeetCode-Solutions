class Solution {
public:
    void bfs(TreeNode* root, vector<vector<int>> &ans){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();     // number of nodes in current level
            vector<int> level;

            for(int i = 0; i < n; i++){
                TreeNode* x = q.front();
                q.pop();
                level.push_back(x->val);
                if(x->left != nullptr) q.push(x->left);
                if(x->right != nullptr) q.push(x->right);
            }
            ans.push_back(level);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        bfs(root, ans);
        return ans;
    }
};