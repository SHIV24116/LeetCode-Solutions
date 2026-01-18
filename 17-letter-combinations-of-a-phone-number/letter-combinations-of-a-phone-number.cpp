class Solution {
public:
    void helper(int i,unordered_map<char, string>& m,string& digits,vector<string>& ans,string& s){
        if (i == digits.size()){
            ans.push_back(s);
            return;
        }

        for (char c : m[digits[i]]) {
            s.push_back(c);
            helper(i + 1, m, digits, ans, s);
            s.pop_back();  
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        vector<string> ans;
        string s;
        helper(0, m, digits, ans, s);
        return ans;
    }
};
