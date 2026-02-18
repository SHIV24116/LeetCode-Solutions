class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool prev;
        prev=((n&1) == 1);
        n=n>>1;
        while(n!=0){
            if(((n&1) == 1)==prev) return false;
            prev= ((n&1) == 1);
            n=n>>1;
        }
        return true;
        
    }
};