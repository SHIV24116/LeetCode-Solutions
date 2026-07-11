class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=1;
        q.push({1,{0,0}});

        int dir1[]={1,-1,0,0,1,1,-1,-1};
        int dir2[]={0,0,1,-1,1,-1,1,-1};

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int d=it.first;
            int i=it.second.first;
            int j=it.second.second;
            if(d>dist[i][j]) continue;

            if(i==n-1 && j==n-1) return dist[i][j];

            for(int k=0;k<8;k++){
                int x=i+dir1[k];
                int y=j+dir2[k];

                if(x>=0 && x<n && y>=0 && y<n && grid[x][y]!=1 && dist[x][y]>(d+1) ){
                    dist[x][y] = d+1;
                    q.push({dist[x][y],{x,y}});
                }
            }
        }
        return -1;
    }
};