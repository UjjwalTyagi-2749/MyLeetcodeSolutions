class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>v(n,-1); 
        queue<int>q;
        
        for(int j=0;j<n;j++){
        if(v[j]!=-1) continue;
        v[j]=0;
        q.push(j);
        
        while(!q.empty()){
            int top=q.front();
            q.pop();

            for(int i:graph[top]){
                if(v[i]==-1){
                    v[i]=1-v[top];
                    q.push(i);
                }
                else if(v[i]==v[top]){
                    return false;
                }
            }
        } 
        }
        return true;
    }
};