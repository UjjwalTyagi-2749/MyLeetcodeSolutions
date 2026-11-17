class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if((i==0 || j==0 || i==r-1||j==c-1 )&&(board[i][j]=='O')){
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
            if(i+1<r && board[i+1][j]=='O'){
                board[i+1][j]='#';
                q.push({i+1,j});
            }
            if(j-1>=0 && board[i][j-1]=='O'){
                board[i][j-1]='#';
                q.push({i,j-1});
            }
            if(j+1<c && board[i][j+1]=='O'){
                board[i][j+1]='#';
                q.push({i,j+1});
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
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