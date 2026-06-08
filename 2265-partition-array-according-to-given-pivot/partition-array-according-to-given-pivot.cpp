class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>a;
        vector<int>b;
        vector<int>c;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot) a.push_back(nums[i]);
            else if(nums[i]==pivot) b.push_back(nums[i]);
            else c.push_back(nums[i]);
        }
        a.insert(a.end(),b.begin(),b.end());
        a.insert(a.end(),c.begin(),c.end());
        return a;  
    }
};