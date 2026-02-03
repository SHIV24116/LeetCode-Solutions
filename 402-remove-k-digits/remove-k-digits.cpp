class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;   // acts as a stack

        for (char c : num) {
            // remove larger previous digits if we can
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        // if deletions remain, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // remove leading zeros
        while(st.size()>1 && st[0]=='0') st.erase(0,1);
        if(st.size()==0) return "0";
        return st;
    }
};
