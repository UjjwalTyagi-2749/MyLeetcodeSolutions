class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>visited(n,false);
        queue<int>q;
        
        q.push(0);
        visited[0]=true;

        while(!q.empty()){
            int top=q.front();
            q.pop();

            for(int i:rooms[top]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
    }
};