class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        unordered_map<int,list<int>>adj;
        for(int i=0;i<dislikes.size();i++){
            int u=dislikes[i][0];
            int v=dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>v(n+1,-1);
        queue<int>q;
        for(int j=1;j<=n;j++){

        if(v[j]!=-1) continue;
        v[j]=1;
        q.push(j);

        while(!q.empty()){
            int top=q.front();
            q.pop();

            for(auto i:adj[top]){
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