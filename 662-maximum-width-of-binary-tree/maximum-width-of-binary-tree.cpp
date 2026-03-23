
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int ans = 0;

        while (!q.empty()) {
            int n = q.size();
            long long start = q.front().second;
            long long first, last;

            for (int i = 0; i < n; i++) {
                auto [node, idx] = q.front();
                q.pop();

                idx -= start;  // normalization

                if (i == 0) first = idx;
                if (i == n - 1) last = idx;

                if (node->left)
                    q.push({node->left, 2 * idx});
                if (node->right)
                    q.push({node->right, 2 * idx + 1});
            }

            ans = max(ans, (int)(last - first + 1));
        }

        return ans;
    }
};