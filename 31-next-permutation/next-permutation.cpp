class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int x=0,y=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<=n-1;j++){
                if(nums[j]>nums[i]){
                    x=i;
                    y=j;
                }
            }
        }
        if(x!=y){
            swap(nums[x],nums[y]);
            sort(nums.begin()+x+1,nums.end());
        }
        else{
            sort(nums.begin(),nums.end());
        }

    }
};