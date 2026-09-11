class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for(int x : digits) freq[x]++;

        int ans = 0;
        for(int num = 100; num <= 999; num++) {
            if(num % 2 != 0) continue;
            int x = num;
            int a = x % 10;
            x /= 10;
            int b = x % 10;
            x /= 10;
            int c = x % 10;
            vector<int> need(10, 0);
            need[a]++;
            need[b]++;
            need[c]++;
            bool possible = true;
            for(int i = 0; i < 10; i++) {
                if(need[i] > freq[i]) {
                    possible = false;
                    break;
                }
            }
            if(possible)  ans++;
        }

        return ans;
    }
};