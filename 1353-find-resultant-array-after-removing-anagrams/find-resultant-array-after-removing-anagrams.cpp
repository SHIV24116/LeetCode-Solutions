class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<int>v;
        for(int i=words.size()-1;i>0;i--){
            string x=words[i];
            sort(x.begin(),x.end());
            string y=words[i-1];
            sort(y.begin(),y.end());
            if(x==y) v.push_back(i);
        }
        sort(v.rbegin(),v.rend());
        for(int i:v){
            words.erase(words.begin()+i);
        }
        return words;
        
    }
};