class Solution {
public:
    string largestOddNumber(string num) {
        int n=-1;
        for(int i=num.size()-1;i>=0;i--){
            int x=num[i]-'0';
            if(x%2!=0){
                n=i;
                break;
            }
        }
        string a="";
        for(int i=0;i<=n;i++){
            a.push_back(num[i]);
        }
        return a;
        
    }
};