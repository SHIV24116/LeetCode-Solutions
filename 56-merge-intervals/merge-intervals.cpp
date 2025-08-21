class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>v;
        sort(intervals.begin(),intervals.end());
        vector<int>temp;
        temp.push_back(intervals[0][0]);
        temp.push_back(intervals[0][1]);
        v.push_back(temp);
        int k=0;
        for(int i=1;i<=intervals.size();i++){
            if(i<intervals.size() && intervals[i][0]<=temp[1] && intervals[i][1]>=temp[0]){
                v[k][1]=max(temp[1],intervals[i][1]);
                v[k][0]=min(temp[0],intervals[i][0]);
                temp[1]=v[k][1];
                temp[0]=v[k][0];
            }
            else{
                if(i<intervals.size()){
                    v.push_back(intervals[i]);
                    k++;
                    temp[0]=intervals[i][0];
                    temp[1]=intervals[i][1];
                }
            }
        }
        return v;
    }
};