class Solution {
public:
    long long smallestNumber(long long num) {
        bool neg=false;
        if(num<0) neg=true;
        num=abs(num);
        vector<int>v;
        int ct=0;
        while(num>0){
            int x=num%10;
            num=num/10;
            if(x==0) ct++;
            else v.push_back(x);
        }
        if(neg){
            sort(v.rbegin(),v.rend());
            long long int r=0;
            for(int i=0;i<v.size();i++){
                r=r*10+v[i];
            }
            while(ct!=0){
                r=r*10;
                ct--;
            }
            return -r;
        }
        sort(v.begin(),v.end());
        long long int x=1;
        long long int ans=0;
        for(int i=0;i<v.size();i++){
            ans=ans*10+v[i];
            if(ct!=0){
                while(ct!=0){
                    ans=ans*10;
                    ct--;
                }
            }
        }
        return ans;
        
    }
};