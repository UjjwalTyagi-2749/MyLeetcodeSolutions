class Solution {
public:
    void topo(int src, vector<vector<int>>&adj,vector<bool>&visited,stack<int>&s,vector<bool>&dfsv,bool & cycle){
        visited[src]=true;
        dfsv[src]=true;

        for(auto neighbour : adj[src]){
            if(dfsv[neighbour]==true){
                cycle=true;
                return;
            }
            if(!visited[neighbour]){
                topo(neighbour,adj,visited,s,dfsv,
                cycle);
            }
        }
        dfsv[src]=false;
        s.push(src);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool>visited(numCourses);
        vector<bool>dfsv(numCourses,false);
        bool cycle=false;
        stack<int>s;
        for(auto i : prerequisites){
            int u=i[0];
            int v=i[1];
            adj[v].push_back(u);
        }

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                topo(i,adj,visited,s,dfsv,cycle);
            }
            if(cycle==true){
                return {};
            }
        }


        vector<int>ans;

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};