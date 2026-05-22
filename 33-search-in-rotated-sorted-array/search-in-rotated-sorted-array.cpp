class Solution {
public:
    int search(vector<int>& nums, int target) {
        int min=*min_element(nums.begin(),nums.end());
        int n=nums.size();
        int x;
        for(int i=0;i<n;i++){
            if(nums[i]==min){
                x=i;
            }
        }
        sort(nums.begin(),nums.end());
        int l=0;
        int h=n-1;
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]==target) return (m+x)%n;
            else if(nums[m]<target) l=m+1;
            else h=m-1;
        }
        return -1;

        
    }
};