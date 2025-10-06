class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        int x=nums1.size();
        if(x%2==0) return (nums1[x/2]+nums1[(x/2)-1])/(float)2;
        return nums1[x/2];
    }
};