class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256, 0);
        for(char c : t) freq[c]++;
        int l = 0, r = 0;
        int ct = 0;
        int start = -1;
        int minLen = INT_MAX;
        while(r < s.size()) {
            // include current char
            if(freq[s[r]] > 0) ct++;
            freq[s[r]]--;
            // when all chars matched
            while(ct == t.size()) {
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0) ct--;
                l++;
            }
            r++;
        }
        if(start == -1) return "";
        return s.substr(start, minLen);
    }
};
