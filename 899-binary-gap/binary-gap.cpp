class Solution {
public:
    int binaryGap(int n) {
        int ct=0;
        bool x=false;
        int ans=0;
        while(n!=0){
            if((n & 1)==1){
                if(x){
                    ct++;
                    ans=max(ans,ct);
                    ct=0;
                }
                else x=true;
            }
            else{
                if(x) ct++;
            }
            n=n>>1;
        }
        return ans;
        
    }
};