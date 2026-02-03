class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>leftsmaller(n);
        vector<int>rightsmaller(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            if(st.empty()) leftsmaller[i]=-1;
            else leftsmaller[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) rightsmaller[i]=n;
            else rightsmaller[i]=st.top();
            st.push(i);
        }
        
        const int M = 1e9 + 7;
        int ans=0;
        for(int i=0;i<n;i++){
           ans = (ans + (int)((1LL * arr[i]*(i-leftsmaller[i])*(rightsmaller[i]-i))%M) ) % M;
        }
        return ans%M;

        
    }
};