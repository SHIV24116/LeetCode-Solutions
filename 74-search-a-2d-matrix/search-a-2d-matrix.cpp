class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            if(target<=matrix[i][n-1] && target>=matrix[i][0]){
                int x=n-1;
                int y=0;
                while(y<=x){
                    int av=(x+y)/2;
                    if(matrix[i][av] == target) return true;
                    else if(matrix[i][av]<target) y=av+1;
                    else x=av-1;
                }
            }
        }
        return false;
        
    }
};