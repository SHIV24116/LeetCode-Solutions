class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxi=bloomDay[0];
        for(int i=1;i<bloomDay.size();i++){
            maxi=max(bloomDay[i],maxi);
        }
        int l=1;
        int h=maxi;
        int d=0;
        while(l<=h){
            int mid=(l+h)/2;
            int b = 0, cnt = 0;
            for (int i = 0; i < bloomDay.size(); i++) {
                if (bloomDay[i] <= mid) {
                    cnt++;
                    if (cnt == k) {
                        b++;
                        cnt = 0;
                    }
                } else {
                    cnt = 0;
                }
            }
            if(b>=m){
                d=mid;
                h=mid-1;
            }
            else l=mid+1;
        }  
        if(d==0) return -1;
        else return d;  
        
    }
};