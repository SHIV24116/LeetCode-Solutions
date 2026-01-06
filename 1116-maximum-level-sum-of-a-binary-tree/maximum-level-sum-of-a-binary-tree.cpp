class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);   // level delimiter

        int level = 1;
        int ans = 1;
        int levelSum = 0;
        int maxSum = INT_MIN;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == NULL) {
                if (levelSum > maxSum) {
                    maxSum = levelSum;
                    ans = level;
                }

                levelSum = 0; 
                level++;

                if (!q.empty())
                    q.push(NULL);

            } else {
                levelSum += curr->val;

                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return ans;
    }
};
