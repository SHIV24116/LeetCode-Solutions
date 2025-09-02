class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        int ct=0;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(points[i][0]>=points[j][0] && points[i][1]<=points[j][1] && i!=j){
                    bool x=true;
                    for(auto m:points){
                        if(m[0]<=points[i][0] && m[0]>=points[j][0] && m[1]<=points[j][1] && m[1]>=points[i][1] && m!=points[i] && m!=points[j]) x=false;
                    }
                    if(x) ct++;
                }
            }
        }
        return ct;
        
    }
};