class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        nums1.erase(unique(nums1.begin(),nums1.end()),nums1.end());
        nums2.erase(unique(nums2.begin(),nums2.end()),nums2.end());
        map<int,int>v;
        for(int i=0;i<nums1.size();i++) v[nums1[i]]++;
        for(int i=0;i<nums2.size();i++) v[nums2[i]]++;
        for(auto& [k,r]:v){
            if(r==2) return k;
        }
        return -1;
    }
};