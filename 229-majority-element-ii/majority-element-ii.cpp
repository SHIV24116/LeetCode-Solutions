class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>v;
        map<int,int>m;
        int n=nums.size();
        for(int i:nums) m[i]++;
        for(auto& [k,val]:m){
            if(val>n/3) v.push_back(k); 
        }
        return v;
    }
};