class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto v:edges){
            adj[v[0]].push_back({v[1],v[2]});
            adj[v[1]].push_back({v[0],v[2]});
        }
        vector<int>r(n,0);

        for(int i=0;i<n;i++){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            vector<int>dist(n,INT_MAX);
            pq.push({0,i});
            dist[i]=0;
            while(!pq.empty()){
                auto it=pq.top();
                pq.pop();
                int w=it.first;
                int node=it.second;
                for(auto idx:adj[node]){
                    int adjnode=idx.first;
                    int wn=idx.second;
                    if(w+wn<dist[adjnode] && w+wn<=distanceThreshold){
                        dist[adjnode]=w+wn;
                        pq.push({w+wn,adjnode});
                    }
                }
            }
            for(int j=0;j<n;j++){
                if(dist[j]!=INT_MAX && i!=j) r[i]++;
            }
             
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(r[i]<=r[ans]) ans=i;
        }
        return ans;
        
    }
};