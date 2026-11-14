class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>>v(n,vector<bool>(n,false));
        queue<pair<int,int>>q;

        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }

        q.push({0,0});
        v[0][0]=true;
        int move=1;
        
        while(!q.empty()){
            int size=q.size();

            while(size--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();

                if(r==n-1 && c==n-1){
                    return move;
                }

                for(int i=r-1;i<=r+1;i++){
                    for(int j=c-1;j<=c+1;j++){
                        if(i== r && j== c){
                            continue;
                        }

                        if(i>=0 && i<n && j>=0  && j<n && grid[i][j]==0){
                            if(v[i][j]==false){
                                v[i][j]=true;
                                q.push({i,j});
                            }
                            
                        }
                    }
                }
            }
            move++;
        }
        return -1;
    }
};