class Solution {
    bool ispres(const string& x, const string& d) {
        for (int i = 0; i + x.size() <= d.size(); i++) {
            if (d.substr(0, x.size()) == x)
                return true;
        }
        return false;
    }

public:
    string longestCommonPrefix(vector<string>& strs) {
        string a = "";
        string ans = "";
        for (char c : strs[0]) {
            a += c;
            bool ok = true;
            for (int j = 1; j < strs.size(); j++) {
                if (!ispres(a, strs[j])) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans = a;
            else break;
        }
        return ans;
    }
};
