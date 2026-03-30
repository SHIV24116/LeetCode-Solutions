class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int>me1;
        unordered_map<char,int>me2;
        unordered_map<char,int>mo1;
        unordered_map<char,int>mo2;
        for(int i=0;i<s1.size();i++){
           if(i%2==0) me1[s1[i]]++;
           else mo1[s1[i]]++;

           if(i%2==0) me2[s2[i]]++;
           else mo2[s2[i]]++;
        }
        for(auto &[k1,v1]:me1){
            bool v=false;
            for(auto &[k2,v2]:me2){
                if(k1==k2 && v1!=v2) return false;
                if(k1==k2) v=true;
            }
            if(!v) return false;
        }
        for(auto &[k1,v1]:mo1){
            bool v=false;
            for(auto &[k2,v2]:mo2){
                if(k1==k2 && v1!=v2) return false;
                if(k1==k2) v=true;
            }
            if(!v) return false;
        }
        return true;
    }
};
 