class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int c=0;
        int x=0;
        for(long long int i:nums){
            if(i==0){
                x++;
                c=c+x;
            }
            else x=0;
        }
        return c;  
    }
};