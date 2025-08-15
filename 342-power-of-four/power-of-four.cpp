class Solution {
public:
    bool isPowerOfFour(int n) {
        bool x=true;
        while(true){
            if(n==0){
                x=false;
                break;
            }
            if(n==1){
                break;
            }
            if(n%4!=0){
                x=false;
                break;
            }
            n=n/4;
        }
        return x;
        
        
    }
};