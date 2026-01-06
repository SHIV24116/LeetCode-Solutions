class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char,char>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]=t[i];
        }
        for(int i=0;i<s.size();i++){
            if(m[s[i]]!=t[i]) return false;
        }
        map<char,char>n;
        for(int i=0;i<s.size();i++){
            n[t[i]]=s[i];
        }
        for(int i=0;i<s.size();i++){
            if(n[t[i]]!=s[i]) return false;
        }return true;
    }
};