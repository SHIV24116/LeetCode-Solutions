class Solution {
public:
    bool dfs(int node,vector<vector<int>>&req,vector<int>&done,vector<int>&ans){
        done[node]=1;
        int n=req[node].size();
        for(int j=0;j<n;j++){
            if(done[req[node][j]]==1) return true;
            if(done[req[node][j]]==0){
                if(dfs(req[node][j],req,done,ans)) return true;
            }
        }
        ans.push_back(node);
        done[node]=2;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>req(numCourses);
        for(auto v:prerequisites){
            req[v[0]].push_back(v[1]);
        }
        vector<int>done(numCourses,0);
        vector<int>ans;
        for(int i=0;i<numCourses;i++){
            if(done[i]==0){
                if(dfs(i,req,done,ans)) return {};
            }
        }
        return ans;
    }
};