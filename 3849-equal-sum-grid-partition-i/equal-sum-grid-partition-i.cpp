class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long int s=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                s=s+grid[i][j];
            }
        }long long int ns=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ns=ns+grid[i][j];
            }
            if(ns==s-ns) return true;
        }ns=0;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                ns=ns+grid[i][j];
            }
            if(ns==s-ns) return true;
        }
        return false;

    }
};