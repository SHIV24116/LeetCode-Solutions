class Solution {
public:
    bool checkOnesSegment(string s) {
        int x=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                if(x==-1) x=i;
                else{
                    if(i-x>1) return false;
                    else x=i;
                }
            }
        }
        return true;
        
    }
};