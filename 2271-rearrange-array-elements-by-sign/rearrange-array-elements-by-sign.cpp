class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int N=nums.size()/2;
        vector<int>p;
        vector<int>n;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0) p.push_back(nums[i]);
            else n.push_back(nums[i]);
        }
        nums.clear();
        int i=0;
        bool x=true;
        while(i<N){
            if(x){
                nums.push_back(p[i]);
                x=false;
            }
            else{
                nums.push_back(n[i]);
                x=true;
                i++;
            }
        }
        return nums;
    }
};