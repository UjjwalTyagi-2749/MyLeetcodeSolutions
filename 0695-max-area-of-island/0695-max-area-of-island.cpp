class Solution {
public:
    int dfs(vector<vector<int>>&grid,int i,int j){
        if(i<0 || j< 0 || i>= grid.size()||j>=grid[0].size() || grid[i][j]!=1){
            return 0;
        }
        int area=0;
        
        grid[i][j]=0;
        area++;
        area+=dfs(grid,i-1,j);
        area+=dfs(grid,i+1,j);
        area+=dfs(grid,i,j-1);
        area+=dfs(grid,i,j+1);
    
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int a=dfs(grid,i,j);
                    ans=max(ans,a);
                }
            }
        }
        return ans;
    }
};