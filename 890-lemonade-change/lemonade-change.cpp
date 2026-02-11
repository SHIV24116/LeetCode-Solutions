class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        bool ans=true;
        int five=0;
        int ten=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                if(five<1){
                    ans=false;
                    break;
                }
                else{
                    ten++;
                    five--;
                }
            }
            else{
                if(five>=3 || (five>=1 && ten>=1)){
                    if(ten!=0){
                        ten--;
                        five--;
                    }
                    else five=five-3;
                }
                else{
                    ans=false;
                    break;
                }
            }
        }
        return ans;
    }
};