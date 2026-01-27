class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i=0;i<n+1;i++){
            int ct=0;
            int x=i;
            while(x!=0){
                if(x&1 ==1) ct++;
                x=x>>1;
            }
            ans[i]=ct;
        }
        return ans;
    }
};