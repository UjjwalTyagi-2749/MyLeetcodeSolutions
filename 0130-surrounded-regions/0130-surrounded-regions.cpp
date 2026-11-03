class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if((i==0||j==0||i==row-1||j==col-1)&&(board[i][j]=='O')){
                    board[i][j]='#';
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            if(i-1>=0 && board[i-1][j]=='O'){
                board[i-1][j]='#';
                q.push({i-1,j});
            }

            if(i+1<row && board[i+1][j]=='O'){
                board[i+1][j]='#';
                q.push({i+1,j});
            }

            if(j-1>=0 && board[i][j-1]=='O'){
                board[i][j-1]='#';
                q.push({i,j-1});
            }

            if(j+1<col && board[i][j+1]=='O'){
                board[i][j+1]='#';
                q.push({i,j+1});
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};