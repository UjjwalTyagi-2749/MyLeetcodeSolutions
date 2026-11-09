class Solution {
public:
    bool bfs(unordered_map<int,list<int>>&adj,int src,int des){
        
        unordered_map<int,bool>visited;
        visited[src]=true;

        queue<int>q;
        q.push(src);

        while(!q.empty()){
            int st=q.front();
            q.pop();
            if(st==des){
                return true;
            }

            for(auto i:adj[st]){

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
       

        for(auto i:edges){
            int u=i[0];
            int v=i[1];

            if(bfs(adj,u,v)){
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