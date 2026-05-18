class Solution {
public:
    void helper(vector<vector<int>>& image,int ac, int i, int j, int color){
        image[i][j]=color;
        if(i+1<image.size() && image[i+1][j]==ac) helper(image,ac,i+1,j,color);
        if(j+1<image[0].size() && image[i][j+1]==ac) helper(image,ac,i,j+1,color);
        if(i>0 && image[i-1][j]==ac) helper(image,ac,i-1,j,color);
        if(j>0 && image[i][j-1]==ac) helper(image,ac,i,j-1,color);
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ac=image[sr][sc];
        if(ac==color) return image;
        helper(image,ac,sr,sc,color);
        return image;
    }
};