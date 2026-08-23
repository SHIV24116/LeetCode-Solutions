class Solution {
public:
    bool sumGame(string num) {
        int lh=0;
        int rh=0;
        int lq=0;
        int rq=0;
        for(int i=0;i<num.size();i++){
           if(i<(num.size()/2)){
                if(num[i]!='?') lh+=(num[i]-'0');
                else lq++;
           }  
           if(i>=(num.size()/2)){
                if(num[i]!='?') rh+=(num[i]-'0');
                else rq++;
           }  
        }
        // Odd number of ? -> Alice wins
        if((lq + rq) % 2 != 0) return true;
        // Alice loses only when the two sides can be made exactly equal
        return 2 * (lh - rh) != 9 * (rq - lq);
    }
};