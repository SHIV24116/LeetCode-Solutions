// class Solution {
// public:
//     string longestPrefix(string s) {
//         string ans="";
//         // string x="";
//         // string y="";
//         for(int i=0;i<s.size()-1;i++){
//             // x=x+s[i];
//             // y=s[s.size()-1-i]+y;
//             int j=s.size()-1-i;
//             if(s.substr(0,i+1)==s.substr(j,i)) ans=s.substr(0,i+1);
//         }
//         return ans;
        
//     }
// };
///////////this solution gives MLE
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n, 0); // For the substring s[0...i], lps[i] = length of the longest proper prefix that is also a suffix.
        int len = 0;
        //len = How many characters of the prefix are currently matching the suffix while we are calculating lps[i].
        int i = 1;
        while(i < n) {
            if(s[i] == s[len]) {
                lps[i] = ++len;
                i++;
            }
            else {
                if(len != 0) len = lps[len - 1];
                else i++;
            }
        }
        return s.substr(0, lps[n - 1]);
    }
};