class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.rbegin(),g.rend());
        sort(s.rbegin(),s.rend());
        int i=0;
        int j=0;
        int ct=0;
        while(j<s.size() && i<g.size()){
            if(s[j]>=g[i]){
                ct++;
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return ct;
    }
};