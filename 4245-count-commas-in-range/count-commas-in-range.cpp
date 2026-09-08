class Solution {
public:
    int countCommas(int n) {
        int x=0;
        int y=n;
        while(n>0){
            n=n/10;
            x++;
        }
        if(x<=3) return 0;
        return y-999;
    }
};