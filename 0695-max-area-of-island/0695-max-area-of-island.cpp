class Solution {
public:
    int dfs(vector<vector<int>>&grid,int i,int j){
        int row=grid.size();
        int col=grid[0].size();
        int count=0;
        if(i<0 || j<0 || i>=row || j>= col || grid[i][j]==0){
            return 0;
        }

        grid[i][j]=0;
        count++;

        count+=dfs(grid,i-1,j);
        count+=dfs(grid,i+1,j);
        count+=dfs(grid,i,j-1);
        count+=dfs(grid,i,j+1);

        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int area=dfs(grid,i,j);
                    maxArea=max(area,maxArea);
                }
            }
        }
        return maxArea;
    }
};