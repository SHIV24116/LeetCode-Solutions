class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area=0;
        int dia=0;
        for(int i=0;i<dimensions.size();i++){
            int a=dimensions[i][0] * dimensions[i][1];
            int d=(dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1]);
            if(d>dia){
                dia=d;
                area=a;
            }
            else if(d==dia) area=max(area,a);
        }
        return area;
        
    }
};