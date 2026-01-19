class Solution {
public:
    bool dfs(int i, int j, int k,vector<vector<char>>& board,string& word) {
        // All characters matched
        if(k == word.size())
            return true;

        // Boundary and mismatch checks
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k]) return false;

        char temp = board[i][j];
        board[i][j] = '#';   // mark visited

        bool found = dfs(i+1,j,k+1,board,word) || dfs(i-1,j,k+1,board,word) || dfs(i,j+1,k+1,board,word) || dfs(i,j-1,k+1,board,word);

        board[i][j] = temp;  // backtrack
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0, board, word)) return true;
            }
        }
        return false;
    }
};
