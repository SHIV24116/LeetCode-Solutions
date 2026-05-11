class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            vector<int>v;
            int x=nums[i];
            while(x>0){
                v.push_back(x%10);
                x=x/10;
            }
            reverse(v.begin(),v.end());
            ans.insert(ans.end(),v.begin(),v.end());
        }
        return ans;
        
    }
};