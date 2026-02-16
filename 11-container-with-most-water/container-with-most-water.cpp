class Solution {
public:
    int maxArea(vector<int>& height) {
        long long maxw = 0;
        int l = 0;
        int r = height.size() - 1;   // FIX

        while (l < r) {
            long long h = min(height[l], height[r]);
            long long a = h * (r - l);
            maxw = max(maxw, a);

            if (height[l] < height[r]) 
                l++;
            else 
                r--;
        }
        return maxw;
    }
};
