class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0;
        int temp=0;
        int ans=0;
        int z=0;
         
        for(int i=0;i<nums.size();i++){
            int f=0;
            if(nums[i]==0){
                temp++; 
                f=z;
                z=0;   
            }
            else{
                z++;
                f=z;
            }
            if(temp%2!=0){
                if(nums[i]==1) l++;
                 
            }
            else{
                l=f;
                if(temp>0) z=0;
                if(temp>0) temp=1;
                
            }
            ans=max(ans,l);
        }
        if(temp==0) return ans-1;
        else return ans;
    }
};