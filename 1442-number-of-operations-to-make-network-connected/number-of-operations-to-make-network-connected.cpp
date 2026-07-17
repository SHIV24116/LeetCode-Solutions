class Solution {
public:
    vector<int>par,size;
    int findUpar(int node){
        if(node==par[node]) return node;
        return par[node]=findUpar(par[node]);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        par.resize(n);
        size.assign(n,1);
        for(int i=0;i<n;i++) par[i]=i;

        for(auto it:connections){
            int x=findUpar(it[0]);
            int y=findUpar(it[1]);
            if(x==y) continue;
            if(size[x]<size[y]){
                par[x]=y;
                size[y]+=size[x];
            }else{
                par[y]=x;
                size[x]+=size[y];
            }
        }
        int d=0;
        for(int i=0;i<n;i++){
            if(i==par[i]) d++;
        }
        return d-1;
    }
};