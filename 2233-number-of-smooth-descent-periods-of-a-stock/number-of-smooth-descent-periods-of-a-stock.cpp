class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long int ct=prices.size();
        long long int x=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i-1]-prices[i]==1) x++;
            if(x!=0 && (prices[i-1]-prices[i]!=1 || i==prices.size()-1)){
                x++;
                ct=ct+x*(x-1)/2;
                x=0;
            }
        }
        return ct;
    }
};