class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x=0;
        int x1=matrix.size()-1;
        int y=matrix[0].size()-1;
        int y1=0;
        int r=matrix.size();
        int c=matrix[0].size();
        int f=(min(r,c)/2) + (min(r,c)%2);
        vector<int>v;
        bool s=true;
        int ct=0;
        int ct1=0;
        int d=0;
        while(f--){
                
                for(int j=d;j<c-ct;j++){
                    v.push_back(matrix[x][j]);
                }
                d++;
                for(int i=d;i<r-ct;i++){
                    v.push_back(matrix[i][y]);
                }
                s=!s;
                x++;
                y--;
                ct++;
             
                for(int j=c-1-ct;j>=ct1;j--){
                    v.push_back(matrix[x1][j]);
                }
                for(int i=r-1-ct;i>=d;i--){
                    v.push_back(matrix[i][y1]);
                }
                s=!s;
                x1--;
                y1++;
                ct1++;
            
             

        }
        v.erase(v.begin()+r*c,v.end());
        return v;
    }
};