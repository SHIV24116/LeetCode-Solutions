class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long s=0;
        for(int i=0;i<piles.size();i++){
            s=s+piles[i];
        }
        long long int l=1;
        long long int hi=s;
        long long int k=s;
        while(l<=hi){
            long long int m=(l+hi)/2;
            long long int hours=0;
            for(int i=0;i<piles.size();i++){
                long long int x=piles[i]/m;
                if(piles[i]%m==0) hours= hours+x;
                else hours= hours+x+1;
            }
            if(hours<=h){
                k=m;
                hi=m-1;
            }
            else{
                l=m+1;
            }
        }
        return k;
    }
};