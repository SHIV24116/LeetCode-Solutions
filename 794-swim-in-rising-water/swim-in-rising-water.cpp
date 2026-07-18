class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> sc(n, vector<int>(n, INT_MAX));

        pq.push({grid[0][0], {0, 0}});
        sc[0][0] = grid[0][0];

        int dirx[] = {-1, 1, 0, 0};
        int diry[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int i = it.second.first;
            int j = it.second.second;

            if (d > sc[i][j]) continue;
            if (i == n - 1 && j == n - 1) return d;
            for (int k = 0; k < 4; k++) {
                int ni = i + dirx[k];
                int nj = j + diry[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                    int newCost = max(d, grid[ni][nj]);
                    if (newCost < sc[ni][nj]) {
                        sc[ni][nj] = newCost;
                        pq.push({newCost, {ni, nj}});
                    }
                }
            }
        }
        return -1;
    }
};