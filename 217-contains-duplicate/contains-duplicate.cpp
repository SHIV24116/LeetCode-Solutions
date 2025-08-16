class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        bool x=false;
        for(auto& [key,va]:m){
           if(va>=2){
              x=true;
              break;}
        }
        return x;
    }
};