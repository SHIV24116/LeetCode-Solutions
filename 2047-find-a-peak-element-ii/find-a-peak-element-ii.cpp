class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int l=0;
        int h=n-1;
        vector<int>v;
        while(l<=h){
            int mid=(l+h)/2;
            int mr=0;
            for(int i=0;i<m;i++){
                if(mat[i][mid]>mat[mr][mid]) mr=i;
            } 
            int left,right;
            if(mid==0 && n==1){
                left=-1;
                right=-1;
            }
            else if(mid==0){
                left=-1;
                right=mat[mr][mid+1];
            }
            else if(mid==n-1){
                left=mat[mr][mid-1];
                right=-1;
            }
            else{
                right=mat[mr][mid+1];
                left=mat[mr][mid-1];
            }
            if(mat[mr][mid]>left && mat[mr][mid]>right){
                v.push_back(mr);
                v.push_back(mid);
                return v;
            }
            else if(mat[mr][mid]<=left) h=mid-1;
            else l=mid+1;
        }
        return v;
    }
};