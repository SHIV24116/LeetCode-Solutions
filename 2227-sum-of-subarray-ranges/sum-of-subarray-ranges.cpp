class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> prevLess(n), nextLess(n), prevGreater(n), nextGreater(n);
        stack<int> st;

        // Previous Less (strict)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            prevLess[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Less or Equal
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            nextLess[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Previous Greater (strict)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater or Equal
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long minCount = (long long)(i - prevLess[i]) * (nextLess[i] - i);
            long long maxCount = (long long)(i - prevGreater[i]) * (nextGreater[i] - i);
            ans += nums[i] * (maxCount - minCount);
        }

        return ans;
    }
};
