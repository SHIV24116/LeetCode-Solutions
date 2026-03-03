class Solution {
public:
    string invert(string s){
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') s[i]='0';
            else s[i]='1';
        }
        return s;
    }
    void strmaker(int n,string &s){
        if(n==0) return;
        string x=invert(s);
        reverse(x.begin(),x.end());
        s=s+"1"+  x;
        strmaker(n-1,s);
    }
    char findKthBit(int n, int k) {
        string s="0";
        strmaker(n-1,s);
        for(int i=0;i<s.size();i++){
            if(i+1==k) return s[i];
        }
        return 0;
    }
};