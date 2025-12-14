class Solution {
public:
    string reverseWords(string s) {
        s=s+" ";
        vector<string>v;
        int x=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ' && x==-1){
                x=i;
            }
            else if(s[i]==' ' && x!=-1){
                v.push_back(s.substr(x,i-x));
                x=-1;
            }
        }
        string ans="";
        for(int i=v.size()-1;i>=0;i--){
            ans=ans+v[i];
            if(i!=0) ans=ans+" ";
        }
        return ans;
    }
};