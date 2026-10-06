class Solution {
public:
    bool path(unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,int source, int destination){
        queue<int>q;
        visited[source]=true;

        q.push(source);
        while(!q.empty()){
            int node=q.front();
            q.pop();

            if(node==destination){
                return true;
            }

            for(auto i:adj[node]){
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
        unordered_map<int,bool>visited;

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans=path(adj,visited,source,destination);
        return ans;
    }
};