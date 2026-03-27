class Solution {
public:
    void helper(TreeNode* node, vector<int>& v1, vector<int>& v2) {
        if (v1.size() == 0) return;

        int j = 0;
        vector<int> x, y;

        for (int i = 0; i < v2.size(); i++) {
            if (v2[i] == v1[0]) {
                j = i;
                break;
            }
            x.push_back(v2[i]);
        }

        for (int i = 1; i <= j; i++) {
            y.push_back(v1[i]);
        }

        // CREATE LEFT NODE
        if (!y.empty()) {
            node->left = new TreeNode(y[0]);
            helper(node->left, y, x);
        }

        vector<int> x1(v1.begin() + j + 1, v1.end());
        vector<int> x2(v2.begin() + j + 1, v2.end());

        // CREATE RIGHT NODE
        if (!x1.empty()) {
            node->right = new TreeNode(x1[0]);
            helper(node->right, x1, x2);
        }
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        helper(root, preorder, inorder);
        return root;
    }
};