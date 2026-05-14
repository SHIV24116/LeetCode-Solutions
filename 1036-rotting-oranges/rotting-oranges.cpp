class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>, int>> q;

        int fresh = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) q.push({{i,j}, 0});
                else if(grid[i][j] == 1) fresh++;
            }
        }
        int ans = 0;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int x = curr.first.first;
            int y = curr.first.second;
            int t = curr.second;
            ans = max(ans, t);
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1){
                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({{nx,ny}, t+1});
                }
            }
        }
        if(fresh > 0) return -1;
        return ans;
    }
};