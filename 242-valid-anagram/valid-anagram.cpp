class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()==t.size()){
           int N=s.size();
           map<char,int>m;
           map<char,int>n;
           for(int i=0;i<N;i++){
               m[s[i]]++;
               n[t[i]]++;
            }
            bool x=true;
            for(auto i:s){
                if(m[i]!=n[i]){ x=false;}
            }
            return x;
        }
        else{
            return false;
        }
        
    }
};