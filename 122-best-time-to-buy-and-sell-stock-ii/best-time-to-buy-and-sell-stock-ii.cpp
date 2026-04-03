class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int c=-1;
        int p=0;
        for(int i=0;i<prices.size()-1;i++){
            if(c!=-1){
                p+=prices[i]-c;
                c=-1;
            }
            if(prices[i]<prices[i+1]) c=prices[i];
        }
        if(c!=-1 && prices[prices.size()-1]>c) p+=prices[prices.size()-1]-c;
        return p;
        
    }
};