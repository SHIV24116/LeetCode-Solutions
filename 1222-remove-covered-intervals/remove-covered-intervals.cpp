class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==1) return 1;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0])
            return a[1] > b[1];   // if first elements are equal, larger second comes first
            return a[0] < b[0];       // otherwise sort by first element ascending
        });

        int ct=0;
        int prevl=intervals[0][0];
        int prevr=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=prevl && intervals[i][1]<=prevr){
                ct++;
            }
            else{
                prevl=intervals[i][0];
                prevr=max(prevr,intervals[i][1]);
            }
        }
        return intervals.size()-ct;
    }
};