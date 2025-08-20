class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v;
        int x=1;
        vector<int>v1;
        while(x<=numRows){
            vector<int>temp;
             
            for(int i=0;i<v1.size();i++){
                temp.push_back(v1[i]);
            }
            if(temp.size()<x) temp.push_back(1);
            v.push_back(temp);
            v1.clear();
            int d=0;
            for(int i=0;i<temp.size();i++){
                d=d+temp[i];
                v1.push_back(d);
                d=temp[i];
            }
            x++;
        }
        return v;
    }
};