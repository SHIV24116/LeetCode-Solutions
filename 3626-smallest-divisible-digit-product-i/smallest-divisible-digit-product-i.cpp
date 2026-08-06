class Solution {
public:
    int product(int x){
        int y=1;
        while(x>0){
            y=y*(x%10);
            x=x/10;
        }
        return y;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(product(n)%t==0) return n;
            n++;
        }
    }
};