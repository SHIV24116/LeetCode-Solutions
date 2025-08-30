class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int x=0;
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target){
                low=mid+1;
                x=mid+1;
            } 
            else{
                high=mid-1;   
                x=mid;
            }
        }
        return x;
        
    }
};