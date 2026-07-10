class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1, INT_MAX);
        // {cost, node}
        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cost = it.first;
            int node = it.second;
              
            if(cost>dist[node]) continue;

            for(auto &x : adj[node]){
                int adjNode = x.first;
                int wt = x.second;
                if(cost + wt < dist[adjNode]){
                    dist[adjNode] = cost + wt;
                    pq.push({cost + wt, adjNode});
                }
            }
        }
        int ans=0;
        for(int i=1;i<n+1;i++){
            if(dist[i]==INT_MAX) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};