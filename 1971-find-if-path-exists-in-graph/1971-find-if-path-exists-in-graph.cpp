class Solution {
public:
    bool bfs(int src,int des,unordered_map<int,list<int>>&adj,unordered_map<int ,bool>&visited){
        queue<int>q;
        visited[src]=true;
        q.push(src);

        while(!q.empty()){
            int top=q.front();
            q.pop();

            if(top==des){
                return true;
            }

            for(int i :adj[top]){
                if(!visited[i]){
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,list<int>>adj;
        unordered_map<int ,bool>visited;

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans=bfs(source,destination,adj,visited);
        return ans;
    }
};