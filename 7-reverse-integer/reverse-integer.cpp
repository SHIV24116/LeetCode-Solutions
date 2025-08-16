class Solution {
public:
    int reverse(int x) {
        long long int a=0;
        while(x!=0){
            a = a*10 + x%10;
            x=x/10;
        }
        long long d=1LL<<31;

        if(a<-d || a>(d-1)){
            return 0;
        }
        else{
            return a;
        }
        
    }
};