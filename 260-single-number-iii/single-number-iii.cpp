class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();i++){
           x=x^nums[i];
        }
        int n1=0;
        int n2=0;
        unsigned int z = (unsigned int)x & (-(unsigned int)x);
        for(int i=0;i<nums.size();i++){
           if((nums[i] & z)==0) n1=n1^nums[i];
           else n2=n2^nums[i];
        }
        return {n1,n2};
        
    }
};