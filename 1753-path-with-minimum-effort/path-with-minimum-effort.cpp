class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<
        pair<int,pair<int,int>>>> pq;

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));

        effort[0][0] = 0;
        pq.push({0,{0,0}});
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int d = cur.first;
            int i = cur.second.first;
            int j = cur.second.second;

            if(d > effort[i][j]) continue;

            for(int k=0;k<4;k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x>=0 && x<n && y>=0 && y<m){
                    int edge = abs(heights[x][y]-heights[i][j]);
                    int newEffort = max(d, edge);
                    if(newEffort < effort[x][y]){   //d is the effort upto node i,j => new effort is eff upto (x,y) in current path
                    // effor[x][y]  is the effort upto x,y through the optimal path
                        effort[x][y] = newEffort;
                        pq.push({newEffort,{x,y}});
                    }
                }
            }
        }

        return effort[n-1][m-1];
    }
};