class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>rem;
        int n=s.size();
        string f="";
        string temp="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                rem.push(s[i]);
                if(rem.size()!=1) temp=temp+s[i];
            }
            else if(s[i]==')'){
                rem.pop();
                if(rem.size()!=0){
                   temp=temp+s[i];
                }
                else{
                    f=f+temp;
                    temp="";
                }
            }
        }
        return f;
    }
};