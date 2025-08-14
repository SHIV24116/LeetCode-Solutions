class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        int x=0;
        string s="";
        for(int i=0;i<=n-3;i++){
            string ans="";
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                ans.push_back(num[i]);
                ans.push_back(num[i+1]);
                ans.push_back(num[i+2]);        
            }
            if(ans.size()==3){
               int d = stoi(ans);
               if(d>=x){
                   x=d;
                   s=ans;
               }
            }

        }
        return s;
        
    }
};