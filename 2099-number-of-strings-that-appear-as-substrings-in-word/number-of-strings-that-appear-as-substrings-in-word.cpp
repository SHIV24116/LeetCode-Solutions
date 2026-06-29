class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ct=0;
        int n=word.size();
        for(string s:patterns){
            int x=s.size();
            for(int i=0;i<n-x+1;i++){
                if(s==word.substr(i,x)){
                    ct++;
                    break;
                }
            }
        }
        return ct;
        
    }
};