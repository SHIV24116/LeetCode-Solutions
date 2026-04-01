class Solution {
public:
    int ans = 0;

    struct NodeInfo {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };

    NodeInfo helper(TreeNode* root) {
        if (!root) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        NodeInfo curr;

        if (left.isBST && right.isBST &&
            root->val > left.maxVal &&
            root->val < right.minVal) {

            curr.isBST = true;
            curr.sum = root->val + left.sum + right.sum;

            ans = max(ans, curr.sum);

            curr.minVal = min(root->val, left.minVal);
            curr.maxVal = max(root->val, right.maxVal);
        } else {
            curr.isBST = false;
            curr.sum = 0;
            curr.minVal = INT_MIN;
            curr.maxVal = INT_MAX;
        }

        return curr;
    }

    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};