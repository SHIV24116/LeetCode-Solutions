class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>leftsmaller(n);
        vector<int>rightsmaller(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) leftsmaller[i]=-1;
            else leftsmaller[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) rightsmaller[i]=n;
            else rightsmaller[i]=st.top();
            st.push(i);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            long long int contri= heights[i]*(rightsmaller[i]-leftsmaller[i]-1);
            ans=max(ans,(int)contri);
        }
        return ans;
        
    }
};