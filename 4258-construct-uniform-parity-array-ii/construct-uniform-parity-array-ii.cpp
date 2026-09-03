class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int sm=INT_MAX;
        int e=0;
        int o=0;
        for(int x:nums1){
            sm=min(sm,x);
            if(x%2==0) e++;
            else o++;
        }
        if(e!=0 && o!=0 && sm%2==0) return false;
        return true;
    }
};