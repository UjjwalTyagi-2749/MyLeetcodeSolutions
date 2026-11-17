class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int r=grid.size();
        int c=grid[0].size();

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if((i==0 || i==r-1 || j==0 || j==c-1)&&(grid[i][j]==1)){
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
            if(i+1<r && grid[i+1][j]==1){
                grid[i+1][j]=0;
                q.push({i+1,j});
            }
            if(j-1>=0 && grid[i][j-1]==1){
                grid[i][j-1]=0;
                q.push({i,j-1});
            }
            if(j+1<c && grid[i][j+1]==1){
                grid[i][j+1]=0;
                q.push({i,j+1});
            }
        }
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }

        return count;
    }
};