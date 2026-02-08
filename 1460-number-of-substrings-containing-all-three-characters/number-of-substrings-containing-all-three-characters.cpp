class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int>freq(3);
        int ans=0;
        int l=0;
        for(int r=0;r<n;r++){
            freq[s[r]-'a']++;     
            while(freq[0]>0 && freq[1]>0 && freq[2]>0){
                ans+= n-r; /// sice r is 0 indexed so no need to add 1
                freq[s[l]-'a']--;
                l++;
            }

        }
        return ans;
    }
};