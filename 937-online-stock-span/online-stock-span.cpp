class StockSpanner {
public:
    StockSpanner() {
        
    }
    vector<int>st;
    int next(int price) {
        int ct=0;
        st.push_back(price);
        for(int i=st.size()-1;i>=0;i--){
            if(st[i]<=price) ct++;
            else break;
        }
        return ct;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */