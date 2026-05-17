class Solution {
public:
    bool helper(int start, vector<int>& arr) {
        if (start < 0 || start >= arr.size() || arr[start] == -1) return false;
        if (arr[start] == 0) return true;

        int jump = arr[start];
        arr[start] = -1;
        return helper(start - jump, arr) || helper(start + jump, arr);
    }
    bool canReach(vector<int>& arr, int start) {
        return helper(start, arr);
    }
};