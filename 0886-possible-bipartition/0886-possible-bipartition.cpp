class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>v(n+1,-1);
        queue<int>q;
        unordered_map<int,list<int>>adj;

        for(int i=0;i<dislikes.size();i++){
            int u=dislikes[i][0];
            int v=dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=1;i<=n;i++){
            if(v[i]!=-1){
                continue;
            }
            v[i]=1;
            q.push(i);

            while(!q.empty()){
                int top=q.front();
                q.pop();

                for(int i:adj[top]){
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