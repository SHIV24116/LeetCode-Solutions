class Solution {
public:
    long long sumAndMultiply(int n) {
        long long int x=0;
        long long int s=0;
        int ct=1;
        while(n>0){
            int k=n%10;
            if(k!=0){
                x=x+k*ct;
                ct=ct*10;
                s=s+k;
            }
            n=n/10;
        }
        return s*x;
    }
};