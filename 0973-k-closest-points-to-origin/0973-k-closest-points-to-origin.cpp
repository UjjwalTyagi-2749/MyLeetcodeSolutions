class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pair<int,int>>h;

        for(int i=0;i<n;i++){
            int x=points[i][0]*points[i][0]+points[i][1]*points[i][1];

            h.push({x,i});
            if(h.size()>k){
                h.pop();
            }
        }

        vector<vector<int>>ans;
        
        while(!h.empty()){
            int x=h.top().second;
            h.pop();

            ans.push_back(points[x]);
        }

        return ans;
    }
};