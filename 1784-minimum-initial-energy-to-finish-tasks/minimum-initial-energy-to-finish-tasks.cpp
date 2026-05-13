class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](vector<int>& a, vector<int>& b){
            return (a[1]-a[0])> (b[1]-b[0]);
        });
         
        int ans=0;
        int renergy=0;
        for(auto& v:tasks){
            if(renergy<v[1]){
                ans=ans+(v[1]-renergy);
                renergy=v[1];
            }
            renergy=(renergy-v[0]);
        }
        return ans;
    }
};