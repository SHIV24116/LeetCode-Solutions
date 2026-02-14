class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>v;
        sort(intervals.begin(),intervals.end());
        v.push_back(intervals[0]);
        if(intervals.size()==1) return v;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>v.back()[1]) v.push_back(intervals[i]);
            else{
                int a=min(intervals[i][0],v.back()[0]);
                int b=max(intervals[i][1],v.back()[1]);
                v.pop_back();
                v.push_back({a,b});
            }
        }
        return v;
    }
};