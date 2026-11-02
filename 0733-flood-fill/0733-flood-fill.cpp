class Solution {
public:
    void dfs(vector<vector<int>>& image,int i,int j,int color,int orgcolor){
        if(i<0 || j< 0 || i>=image.size()|| j>=image[0].size()||image[i][j]==color || image[i][j]!=orgcolor){
            return;
        }

        image[i][j]=color;

        dfs(image,i-1,j,color,orgcolor);
        dfs(image,i,j+1,color,orgcolor);
        dfs(image,i+1,j,color,orgcolor);
        dfs(image,i,j-1,color,orgcolor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};