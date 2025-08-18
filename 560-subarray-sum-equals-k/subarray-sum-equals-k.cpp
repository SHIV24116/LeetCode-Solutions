class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>hsh(nums.size()+1);
        int sum=0;
        hsh[0]=0;
        for(int i=0;i<nums.size();i++){
             
            hsh[i+1]=hsh[i]+nums[i];
             
        }
        int ct=0;
        for(int i=0;i<=nums.size()-1;i++){
            for(int j=nums.size();j>i;j--){
                if(hsh[j]-hsh[i]==k) ct++;
            }
        }
        return ct;
    }
};