class Solution {
public:
    bool parseBoolExpr(string expression) {
        vector<char> st;
        for(char c : expression) {
            if(c == ',') continue;
            if(c != ')') st.push_back(c);
            else{
                // Evaluate everything inside this (...)
                bool hasTrue = false;
                bool hasFalse = false;
                while(st.back() != '(') {
                    char x = st.back();
                    st.pop_back();
                    if(x == 't') hasTrue = true;
                    else if(x == 'f') hasFalse = true;
                }
                // Remove '('
                st.pop_back();
                // Operator is now on top
                char op = st.back();
                st.pop_back();
                bool result;
                if(op == '&') result = !hasFalse;
                else if(op == '|') result = hasTrue;
                else result = hasFalse;
                // Store result of this whole expression
                st.push_back(result ? 't' : 'f');
            }
        }
        return st.back() == 't';
    }
};