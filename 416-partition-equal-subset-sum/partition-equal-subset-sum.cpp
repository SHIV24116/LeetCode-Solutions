class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        for(int i=0;i<nums.size();i++) s+=nums[i];    
        if(s%2==1) return false;    

        int k=s/2;
        vector<bool>prev(k+1,false);
        prev[0]=true;
        for(int i=0;i<nums.size();i++){
            vector<bool>curr(k+1,false);
            curr[0]=true;
            for(int target=1;target<k+1;target++){
                bool nottaken=prev[target];
                bool taken=false;
                if(nums[i]<=target){
                    taken=prev[target-nums[i]];
                }
                curr[target]=taken || nottaken;
            }
            prev=curr;
        }
        return prev[k];
    }
};