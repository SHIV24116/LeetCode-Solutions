class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]}); //since roads are bidirectional
        }
        vector<int>sc(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({INT_MAX,1});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int s=it.first;
            int node=it.second;


            for(auto k:adj[node]){
                int adjnode=k.first;
                int w=k.second;
                int score=min(s,w);
                if(score<sc[adjnode]){
                    sc[adjnode]=score;
                    pq.push({score,adjnode});
                }
            }
        }
        return sc[n];
    }
};