class Solution {
public:
    bool dfs(int i,vector<int>&vis,vector<vector<int>>& graph,vector<int>& notsafe){
        if(notsafe[i]==1) return true;
        vis[i]=1;
        for(int j:graph[i]){
            if(vis[j]==0){
                if(dfs(j,vis,graph,notsafe)){
                    notsafe[i]=1;
                    return true;
                }
            }
            else if(vis[j]==1){
                notsafe[i]=1;
                return true;
            }
            else if(notsafe[j]) {        // vis[j] == 2 but j is unsafe
                notsafe[i] = 1;
                return true;
            }
        }
        vis[i]=2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>notsafe(n,0);
        vector<int>ans;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0) dfs(i, vis, graph, notsafe);
        }
        for(int i = 0; i < n; i++){
            if(!notsafe[i]) ans.push_back(i);
        }
        return ans;
    }
};