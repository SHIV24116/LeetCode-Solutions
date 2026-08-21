class Solution {
public:
    bool isPredecessor(string a, string b) {
        // a should be shorter
        if (b.size() != a.size() + 1) return false;
        int i = 0, j = 0;
        //We use LongestCommonSequence(LCS)...when we dont know which index to skip(w1's char or w2's char)
        //But in String Chain, we know the exact condition...each time char not matches skip the w2's char 
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            }
            else {
            // Skip one character from b
                j++;
            }
        }
        return i == a.size();
    } 
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(), words.end(),[](string &a, string &b) {
            return a.size() < b.size();
        }); ////since we don't need to preserve any order of the words...can take any order and sorting will be the best order for predecessors

        vector<int>dp(n,1);  //dp denotes the length of the longest valid string chain ending at words[i].
        vector<int>prev(n,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if (words[j].size() + 1 != words[i].size()) continue;
                if(dp[j]+1>dp[i] && isPredecessor(words[j],words[i])){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};