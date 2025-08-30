class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool a=true;
        for(int i=0;i<9;i++){
            unordered_map<char,int>x;
            unordered_map<char,int>y;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.') x[board[i][j]]++;
                if(board[j][i]!='.') y[board[j][i]]++;
            }
            for(auto& [k,v]:x){
                if(v>1) a=false;
            }
            for(auto& [k,v]:y){
                if(v>1) a=false;
            }
        }
        int i=0;
        int j=0;
        while(i<=6 && j<=6){
            unordered_map<char,int>m;
            for(int x=i;x<=i+2;x++){
                for(int y=j;y<=j+2;y++){
                    if(board[x][y]!='.') m[board[x][y]]++;
                }
            }
            for(auto& [k,v]:m){
                if(v>1) a=false;
            }
            if(j+3<=6) j+=3;
            else{
                i+=3;
                j=0;
            }
        }
        return a;
        
    }
};