class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ct=0;
        int i=0;
        while(i<32){
            if((start & 1) != (goal & 1)) ct++;
            i++;
            start>>=1;
            goal>>=1;
        }
        return ct;
    }
};