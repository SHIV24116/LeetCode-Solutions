class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0;
        vector<int>f(26,0);
        int ans=INT_MIN;
        for(int r=0;r<s.size();r++){
            f[s[r]-'a']++;
            while(f[s[r]-'a']>2){
                f[s[l]-'a']--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
        
    }
};