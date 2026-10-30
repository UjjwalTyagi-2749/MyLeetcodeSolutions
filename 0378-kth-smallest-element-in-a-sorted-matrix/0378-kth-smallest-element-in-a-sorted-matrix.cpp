class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>h;

        for(auto i:matrix){
            for(int x:i){
                h.push(x);
                if(h.size()>k){
                    h.pop();
                }
            }
        }
        return h.top();
    }
};