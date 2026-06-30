class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(vis[it] == 1) return true;   //vis[it]=0....unvisited,1.....visiting,2.....visited
            if(vis[it] == 0){
                if(dfs(it, adj, vis)) return true;     //for node to become visited(completable course) all its prerequisites must be either 0(not explored yet) or 2(already completed)
            }
        }
        vis[node] = 2;   //once all prerequisites of the node are explored....it is marked visited.
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            if(vis[i] == 0) {
                if(dfs(i, adj, vis)) return false;    //dfs true means there is a cycle in the graph=>this course can not be completed
            }
        }
        return true;
    }
};