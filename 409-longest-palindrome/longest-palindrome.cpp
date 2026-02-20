class Solution {
public:
    int longestPalindrome(string s) {
        bool o=false;
        unordered_map<char,int>m;
        for(char c:s){
            m[c]++;
        }
        int ans=0;
        for(auto &[k,v]:m){
            if(v%2==0) ans+=v;
            else{
                o=true;
                ans+=(v-1);
            }
        }
        if(o) return ans+1;
        return ans; 
    }
};