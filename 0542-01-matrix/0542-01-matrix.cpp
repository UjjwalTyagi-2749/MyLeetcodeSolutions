class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r= mat.size();
        int c=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>dis(r,vector<int>(c,-1));

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==0){
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }


        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;

            q.pop();


            if(i-1>=0 && dis[i-1][j]==-1){
                q.push({i-1,j});
                dis[i-1][j]=dis[i][j]+1;
            }
            if(i+1<r && dis[i+1][j]==-1){
                q.push({i+1,j});
                dis[i+1][j]=dis[i][j]+1;
            }
            if(j-1>=0 && dis[i][j-1]==-1){
                q.push({i,j-1});
                dis[i][j-1]=dis[i][j]+1;
            }
            if(j+1<c && dis[i][j+1]==-1){
                q.push({i,j+1});
                dis[i][j+1]=dis[i][j]+1;
            }
        }
        return dis;
    }
};