class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ct = 0;
        int n = word.size();
        for (string s : patterns) {
            int x = s.size();
            bool v = false;
            for (int st = 0; st <= n - x; st++) {      ////in this loop we are conceptually implementing word.find(s) which returns the first occurence of s in word and if not present returns  "std::string::npos"
                int j = 0;
                while (j < x && word[st + j] == s[j])
                    j++;
                if (j == x) {
                    v = true;
                    break;
                }
            }
            if (v) ct++;
        }
        return ct;
    }
};