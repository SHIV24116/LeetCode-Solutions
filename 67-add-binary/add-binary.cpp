class Solution {
public:
    string addBinary(string a, string b) {
        string s="";
        int x = abs((int)a.size() - (int)b.size());
        if(a.size()>b.size()){
            while(x>0){
                b='0'+b;
                x--;
            }
        }
        else{
            while(x>0){
                a='0'+a;
                x--;
            }
        }
        int c=0;
        for(int i=a.size()-1;i>=0;--i){
           if(a[i]=='1' && b[i]=='1'){
            if(c==0) s='0'+s;
            else s='1'+s;
            c=1;
           }
           if((a[i]=='1' && b[i]=='0') || (a[i]=='0' && b[i]=='1')){
            if(c==0) s='1'+s;
            else s='0'+s;
           }
           if(a[i]=='0' && b[i]=='0'){
            if(c==0) s='0'+s;
            else{
                s='1'+s;
                c=0;
            }
           }
        }
        if(c==1) s='1'+s;
        return s;
    }
};