class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k) return false;
        vector<string>v;
        for(int i=0;i<s.size()-k+1;i++){
           v.push_back(s.substr(i,k));
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        if(v.size() >= 1<<k) return true;
        return false;
    }
};