class Solution {
public:

    // Step 1: Find the horizontal range of the tree
    void findRange(TreeNode* node, int x, int &minX, int &maxX){
        if(!node) return;

        minX = min(minX, x); // leftmost column
        maxX = max(maxX, x); // rightmost column

        findRange(node->left, x-1, minX, maxX);
        findRange(node->right, x+1, minX, maxX);
    }

    // Step 2: DFS traversal to fill data
    void dfs(TreeNode* node, int x, int y,
             vector<vector<pair<int,int>>>& ans, int minX){

        if(!node) return;

        // Shift index: (x - minX) makes index non-negative
        // Store {row, value} → needed for sorting later
        ans[x - minX].push_back({y, node->val});

        dfs(node->left, x-1, y+1, ans, minX);
        dfs(node->right, x+1, y+1, ans, minX);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int minX = 0, maxX = 0;
        findRange(root, 0, minX, maxX);

        int width = maxX - minX + 1;

        // ans[i] will store all nodes belonging to column i
        // Each node stored as {row (y), value}
        vector<vector<pair<int,int>>> ans(width);

        dfs(root, 0, 0, ans, minX);

        // Final result
        vector<vector<int>> result;

        //Sort each column
        for(auto &col : ans){

            // Sorting rules:
            // Smaller row (y) first → top to bottom
            // If same row → smaller value first
            sort(col.begin(), col.end(), [](auto &a, auto &b){
                if(a.first == b.first)
                    return a.second < b.second; // value comparison
                return a.first < b.first;       // row comparison
                }
            );

            // Extract only values (ignore row now)
            vector<int> temp;
            for(auto &p : col){
                temp.push_back(p.second);
            }

            result.push_back(temp);
        }

        return result;
    }
};