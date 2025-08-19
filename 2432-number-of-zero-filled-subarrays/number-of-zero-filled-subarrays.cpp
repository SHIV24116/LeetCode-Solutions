class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int ct=0;
         
        int x=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                x++;
                ct=ct+x;
            }
            else{
                x=0;
            }
        }
        return ct;

        
    }
};