class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int x;
        for(int i=0;i<=n;i++){
            bool z=false;
            for(auto j:nums){
                if(j==i){
                    z=true;
                }
            }
            if(z==false){
                x= i;
            }
        } 
        return x;  
    }
};