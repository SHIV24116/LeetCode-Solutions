class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ct=0;
        vector<bool>v(33,true);
        v[0]=v[1]=false;
        for(int i=2;i<33;i++){
            if(v[i]){
                for(long long j=1LL*i*i;j<33;j+=i){
                    v[j]=false;
                }
            }
        }
        for(int i=left;i<=right;i++){
            if(v[__builtin_popcount(i)]) ct++;
        }
        return ct;
    }
};