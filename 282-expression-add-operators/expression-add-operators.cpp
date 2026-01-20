class Solution {
public:
    void helper(int i,string curr,vector<string>& ans,long value,long last,string& num,int target) {
        // base case
        if (i == num.size()) {
            if (value == target) {
                ans.push_back(curr);
            }
            return;
        }
        // try all possible numbers starting at index i
        for (int j = i; j < num.size(); j++) {
            // leading zero check
            if (j > i && num[i] == '0') break;

            string part = num.substr(i, j - i + 1);
            long currNum = stoll(part);

            if (i == 0) {
                // first number: no operator
                helper(j + 1, part, ans, currNum, currNum, num, target);
            } else {
                // '+'
                helper(j + 1,curr + "+" + part,ans,value + currNum,currNum,num,target);
                // '-'
                helper(j + 1,curr + "-" + part,ans,value - currNum,-currNum,num,target);
                // '*'
                helper(j + 1,curr + "*" + part,ans,value - last + last * currNum,last*currNum,num,target);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        helper(0, "", ans, 0, 0, num, target);
        return ans;
    }
};
