class Solution {
public:
    bool dfs(int i, string &s,unordered_set<string>& dict,vector<int>& memo) {

        if (i == s.size())
            return true;

        if (memo[i] != -1)
            return memo[i];

        for (int j = i + 1; j <= s.size(); j++) {
            if (dict.count(s.substr(i, j - i)) &&
                dfs(j, s, dict, memo)) {
                return memo[i] = true;
            }
        }

        return memo[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        return dfs(0, s, dict, memo);
    }
};
