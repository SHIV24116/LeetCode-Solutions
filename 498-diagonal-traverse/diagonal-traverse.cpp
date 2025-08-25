class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int i=0;
        int j=0;
        vector<int>v;
        int m=mat.size();
        int n=mat[0].size();
        int dir=-1;
        while(v.size()<m*n){
            v.push_back(mat[i][j]);
            if(dir==-1){
                if(i==0 && j==n-1){
                    i++;
                    dir=1;
                }
                else if(i==0){
                    j++;
                    dir=1;
                }
                else if(j==n-1){
                    i++;
                    dir=1;
                }
                else{
                    i--;
                    j++;
                } 
            }
            else if(dir==1){
                if(j==0 && i==m-1){
                    dir=-1;
                    j++;
                }
                else if(j==0){
                    dir=-1;
                    i++;
                }
                else if(i==m-1){
                    dir=-1;
                    j++;
                }
                else{
                    i++;
                    j--;
                } 
            }
        }
        return v;
         
    }
};