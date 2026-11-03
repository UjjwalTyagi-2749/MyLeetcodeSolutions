class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>>dist(row,vector<int>(col,-1));
        queue<pair<int,int>>q;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            if(i-1>=0 && dist[i-1][j]==-1){
                q.push({i-1,j});
                dist[i-1][j]=dist[i][j]+1;
            }

            if (i + 1 < row && dist[i+1][j] == -1) {
                dist[i+1][j] = dist[i][j] + 1;
                q.push({i+1, j});
            }
           
            if (j - 1 >= 0 && dist[i][j-1] == -1) {
                dist[i][j-1] = dist[i][j] + 1;
                q.push({i, j-1});
            }
            
            if (j + 1 < col && dist[i][j+1] == -1) {
                dist[i][j+1] = dist[i][j] + 1;
                q.push({i, j+1});
            }
        }
        return dist;
    }
};