class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if((i==0||j==0||i==row-1||j==col-1 )&&(grid[i][j]==1)){
                    grid[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            if(i-1>=0 && grid[i-1][j]==1){
                grid[i-1][j]=0;
                q.push({i-1,j});
            }

            if(i+1<row && grid[i+1][j]==1){
                grid[i+1][j]=0;
                q.push({i+1,j});
            }

            if(j-1>=0 && grid[i][j-1]==1){
                grid[i][j-1]=0;
                q.push({i,j-1});
            }

            if(j+1<col && grid[i][j+1]==1){
                grid[i][j+1]=0;
                q.push({i,j+1});
            }
        }
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};