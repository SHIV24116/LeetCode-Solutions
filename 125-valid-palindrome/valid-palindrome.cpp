class Solution {
  
public:
    bool isPalindrome(string s) {
        int n=s.length();
        string l="";
        for(int i=0;i<n;i++){
            if(isalnum(s[i])){
                s[i]=tolower(s[i]);
                l.push_back(s[i]);
            }
            

        }
        bool f=true;
        for(int i=0;i<l.size()/2;i++){
            if(l[i]!=l[l.size()-1-i]){
                f=false;
            }
        }
        return f;

    }
};