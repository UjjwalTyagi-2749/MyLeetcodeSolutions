class Solution {
public:
    void dfss(int src,int des,vector<int>&path,vector<vector<int>>&ans,vector<vector<int>>& graph){
        path.push_back(src);
        if(src==des){
            ans.push_back(path);
        }
        else{
            for(int i:graph[src]){
            dfss(i,des,path,ans,graph);
            }
        }

        path.pop_back();

        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>path;

        int n=graph.size();

        
        dfss(0,n-1,path,ans,graph);
        return ans;
    }
};