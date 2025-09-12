class Solution {
public:
    bool doesAliceWin(string s) {
        int ct=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') ct++;
        }
        if(ct==0) return false;
        return true;
    }
};