class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<long long int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int x=0;
        int f=0;
        for(auto &[key,value]:m){
                if(value>=n/2 && value>=f){
                    x=key;
                    f=value;
                }
        }
        return x;
    }
};