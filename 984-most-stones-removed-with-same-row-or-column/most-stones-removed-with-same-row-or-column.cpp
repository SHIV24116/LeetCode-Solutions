class Solution {
public:
    vector<int>par,size;
    int findUPar(int node){
        if(node==par[node]) return node;
        return par[node]=findUPar(par[node]);
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        par.resize(n);
        size.assign(n,1);
        for(int i=0;i<n;i++) par[i]=i;
        
        for(int i=0;i<n;i++){
            int r=stones[i][0];
            int c=stones[i][1];
            for(int j=i+1;j<n;j++){
                if((r==stones[j][0] || c==stones[j][1])){
                    int p1=findUPar(j);
                    int p2=findUPar(i);
                    
                    if(p1==p2) continue;

                    if(size[p1]<size[p2]){
                       par[p1]=p2;
                       size[p2]+=size[p1];
                    }else{
                        par[p2]=p1;
                        size[p1]+=size[p2];
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==par[i]){       //ultimate parents are the only one's which are their own parents
                ans+=size[i]-1;
            }
        }
        return ans;
    }
};