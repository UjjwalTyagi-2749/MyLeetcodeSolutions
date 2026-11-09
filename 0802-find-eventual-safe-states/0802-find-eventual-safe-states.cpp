class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int,list<int>>adj;
        int n=graph.size();
        vector<int>indegree(n,0);
        queue<int>q;
        vector<int>ans;

        for(int i=0;i<n;i++){
            for(int j:graph[i]){
                adj[j].push_back(i);
            }
        }

        for(auto i:adj){
            for(auto j:i.second){
                indegree[j]++;
            }
        }

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int top=q.front();
            q.pop();
            ans.push_back(top);

            for(int i:adj[top]){
                indegree[i]--;

                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};