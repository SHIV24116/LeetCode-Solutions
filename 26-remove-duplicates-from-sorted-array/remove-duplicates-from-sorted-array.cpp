class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        nums.clear();
        for(auto& [key,val]:m){
            nums.push_back(key);
            val--;
        }
        for(auto& [key,val]:m){
            nums.insert(nums.end(),val,key);
        }

        int x=m.size();
        return x;
        
    }
};