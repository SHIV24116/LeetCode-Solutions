class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>I;
        vector<int>J;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    I.push_back(i);
                    J.push_back(j);
                }
            }
        }
        for(auto i:I){
            for(int j=0;j<n;j++){
                matrix[i][j]=0;
            }
        }
        for(auto j:J){
            for(int i=0;i<m;i++){
                matrix[i][j]=0;
            }
        }


    }
};