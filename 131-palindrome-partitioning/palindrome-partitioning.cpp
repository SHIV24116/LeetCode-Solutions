class Solution {
public:
    bool ispalindrome(string s,int l,int r){
        while(l<=r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void helper(int i,string s,vector<vector<string>>&ans,vector<string>&curr){
        if(i==s.size()){
            ans.push_back(curr);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(ispalindrome(s,i,j)){
                curr.push_back(s.substr(i,j-i+1));
                helper(j+1,s,ans,curr);
                curr.pop_back();
            }

        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;
        helper(0,s,ans,curr);
        return ans;
    }
};