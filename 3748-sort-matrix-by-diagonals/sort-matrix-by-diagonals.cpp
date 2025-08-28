class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0;i<n;i++){
            vector<int>v;
            int x=i;
            int j=0;
            while(x<n && j<n){
                v.push_back(grid[x][j]);
                x++;
                j++;
            }
            x=i;
            j=0;
            sort(v.begin(),v.end());
            reverse(v.begin(),v.end());
            while(x<n && j<n){
                grid[x][j]=v[j];
                j++;
                x++;
            }
        }
        for(int i=1;i<n;i++){
            vector<int>v;
            int x=i;
            int j=0;
            while(x<n && j<n){
                v.push_back(grid[j][x]);
                x++;
                j++;
            }
            x=i;
            j=0;
            sort(v.begin(),v.end());
            while(x<n && j<n){
                grid[j][x]=v[j];
                j++;
                x++;
            }
        }
        return grid;
    }
};