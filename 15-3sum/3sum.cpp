class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>>v;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int t=0-nums[i];
            int left=i+1;
            int right=n-1;
            while(left<n-1 && right>left){
                if(nums[left]+nums[right]==t){
                    v.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1] && nums[right]==nums[right+1]){
                        left++;
                        right--;
                    }
                }
                else if(nums[left]+nums[right]>t) right--;
                else left++;
            }
        }
        set<vector<int>>s;
        s.insert(v.begin(),v.end());
        vector<vector<int>>a;
        for(auto i:s){
            a.push_back(i);
        }
        return a;
        
        
    }
};