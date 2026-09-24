class Solution {
public:
    bool cycle(int src,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsv,vector<vector<int>>& adj){
        visited[src]=true;
        dfsv[src]=true;

        for(auto neighbour :adj[src]){
            if(!visited[neighbour]){
                bool detected=cycle(neighbour,visited,dfsv,adj);
                if(detected==true){
                    return true;
                }
                
            }

            else if(dfsv[neighbour]){
                return true;
            }
        }
        dfsv[src]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsv;
        vector<vector<int>>adj(numCourses);

        for(auto x : prerequisites){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
        }

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                bool ans=cycle(i,visited,dfsv,adj);

                if(ans){
                    return false;
                }
            }
        }
        return true;
    }
};