class Solution {
public:
    bool checkDivisibility(int n) {
        int x=n;
        int d=0;
        int m=1;
        while(x>0){
            int y=x%10;
            d+=y;
            m*=y;
            x=x/10;
        }
        if(n%(d+m)==0) return true;
        return false;
    }
};