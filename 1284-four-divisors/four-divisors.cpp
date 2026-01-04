class Solution {
public:
    bool isPrime(int x){
        if(x<2) return false;
        for(int i=2;i*i<=x;i++){
            if(x%i==0) return false;
        }return true;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int x:nums){
            for(int d=2;d*d<=x;d++){
                if(x%d==0){
                    int d1=d;
                    int d2=x/d;
                    if(d1!=d2 && isPrime(d1) && (isPrime(d2) || d2==d1*d1)) ans+=(1+d1+d2+x);
                    break;
                }
            }
        }return ans;
    }
};
