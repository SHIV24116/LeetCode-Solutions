class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent = NULL;
        TreeNode* curr = root;

        // find node
        while(curr && curr->val != key){
            parent = curr;
            if(key > curr->val) curr = curr->right;
            else curr = curr->left;
        }

        if(curr == NULL) return root; // not found

        // case 1: node has 0 or 1 child
        if(curr->left == NULL || curr->right == NULL){
            TreeNode* child = curr->left ? curr->left : curr->right;

            if(parent == NULL) return child; // deleting root

            if(parent->left == curr) parent->left = child;
            else parent->right = child;
        }
        else{
            // case 2: two children → find inorder successor
            TreeNode* succParent = curr;
            TreeNode* succ = curr->right;

            while(succ->left){
                succParent = succ;
                succ = succ->left;
            }

            // replace value
            curr->val = succ->val;

            // delete successor
            if(succParent->left == succ)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;
        }

        return root;
    }
};