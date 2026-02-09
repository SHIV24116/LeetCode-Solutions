class Solution {
public:
    int atMostK(vector<int>& nums, int k){
        if(k < 0) return 0;

        unordered_map<int,int> freq;
        int l = 0;
        int ans = 0;

        for(int r = 0; r < nums.size(); r++){
            if(freq[nums[r]] == 0) k--;
            freq[nums[r]]++;

            while(k < 0){
                freq[nums[l]]--;
                if(freq[nums[l]] == 0) k++;
                l++;
            }

            ans += (r - l + 1);
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
