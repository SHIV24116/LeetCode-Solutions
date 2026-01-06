class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        int n=s.size();
        while(n>0){
            char x=s[0];
            s.erase(0,1);
            s=s+x;
            n--;
            if(s==goal) return true;
        }return false;
    }
};