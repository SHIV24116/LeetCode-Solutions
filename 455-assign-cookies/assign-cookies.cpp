class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=s.size();
        int m=g.size();
        sort(g.rbegin(),g.rend());
        sort(s.rbegin(),s.rend());
        int i=0;
        int j=0;
        while(j<n && i<m){
            if(s[j]>=g[i]) j++;
            i++;
        }
        return j;
    }
};