class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26);
        int l=0;
        int maxf=0;
        int ans=0;
        for(int r=0;r<s.size();r++){
            freq[s[r]-'A']++;
            maxf=max(maxf,freq[s[r]-'A']);
            int change=(r-l+1)-maxf;
            while(change>k){
                freq[s[l]-'A']--;
                if(maxf==freq[s[l]-'A']) maxf--;
                l++;
                change=(r-l+1)-maxf;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};