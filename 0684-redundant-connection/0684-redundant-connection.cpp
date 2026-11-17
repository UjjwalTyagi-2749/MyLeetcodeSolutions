class Solution {
public:
    bool bfs(int src,int des,unordered_map<int,list<int>>&adj){
        unordered_map<int,bool>visited;
        visited[src]=true;
        queue<int>q;
        q.push(src);

        while(!q.empty()){
            int top=q.front();
            q.pop();

            if(top==des){
                return true;
            }

            for(int i:adj[top]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,list<int>>adj;

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            if(bfs(u,v,adj)){
                return {u,v};
            }
            else{
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        return {};
    }
};