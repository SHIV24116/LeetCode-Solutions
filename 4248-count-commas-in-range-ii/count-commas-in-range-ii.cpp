class Solution {
public:
    long long countCommas(long long n) {
        int x=0;
        long long y=n;
        while(y>0){
            x++;
            y=y/10;
        }
        if(x<=3) return 0;
        else if(x<=6) return n-999;
        else if(x<=9) return 999000+(n-999999)*2;
        else if(x<=12) return 999000+999000000*2+3*(n-999999999);
        else if(x<=15) return 999000+999000000*2+3*999000000000+4*(n-999999999999);
        else return 999000+999000000*2+3*999000000000+4*(n-999999999999)+1;
    }
};