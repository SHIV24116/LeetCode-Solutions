class Solution {
public:
    int minOperations(string s) {
        int o=0;
        int e=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                if(s[i]!='1') e++;
                if(s[i]!='0') o++;
            }
            else{
                if(s[i]!='1') o++;
                if(s[i]!='0') e++;
            }
        }
        return min(e,o);
        
    }
};