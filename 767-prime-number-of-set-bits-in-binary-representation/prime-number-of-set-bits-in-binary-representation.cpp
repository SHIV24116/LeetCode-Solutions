class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ct=0;
        vector<bool>v(1e5+1,true);
        v[0]=v[1]=false;
        for(int i=2;i<1e5+1;i++){
            if(v[i]){
                for(long long j=1LL*i*i;j<1e5+1;j+=i){
                    v[j]=false;
                }
            }
        }
        for(int i=left;i<=right;i++){
            int x=__builtin_popcount(i);
            if(v[x]) ct++;
        }
        return ct;
    }
};