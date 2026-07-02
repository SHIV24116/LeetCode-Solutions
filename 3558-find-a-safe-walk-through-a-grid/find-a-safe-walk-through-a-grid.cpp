class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        deque<pair<int,int>> dq;  // since all edges do not have same weights so we can use Dijkshtra(priority Queue) algo.
        //but since there are only two possible edge weights so can use Deque which will be faster.
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX)); 
        dist[0][0] = grid[0][0];   
        dq.push_front({0,0});

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!dq.empty()){
            auto [r,c] = dq.front();
            dq.pop_front();
            for(int k=0;k<4;k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
                int newCost = dist[r][c] + grid[nr][nc];
                if(newCost < dist[nr][nc]){
                    dist[nr][nc] = newCost;
                    if(grid[nr][nc] == 0) dq.push_front({nr,nc}); //weight 1.... one side(front)
                    else dq.push_back({nr,nc});  //weight 0...other side(back)
                }
            }
        }

        //we just calculayed min health cost to reach (n-1,m-1)
        return dist[n-1][m-1] < health;
    }
};