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
        if(n==-1) return "";
        else return num.substr(0,n+1);
        
    }
};