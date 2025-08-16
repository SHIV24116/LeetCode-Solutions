class Solution {
public:
    int maximum69Number (int num) {
        vector<int>v;
        while(num>0){
            v.push_back(num%10);
            num = num/10;
        }
        int x=0;
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]==6){
                v[i]=9;
                break;
            }
        }
        for(int i=v.size()-1;i>=0;i--){
            x=x*10+v[i];
        }
        return x;
        
    }
};