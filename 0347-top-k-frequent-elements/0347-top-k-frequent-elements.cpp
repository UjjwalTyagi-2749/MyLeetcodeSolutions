class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        priority_queue<pair<int,int>>h;

        for(int i:nums){
            m[i]++;
        }

        for(auto i :m){
            h.push({i.second,i.first});
        }

        vector<int>ans;

        while(k>0){
            ans.push_back(h.top().second);
            h.pop();
            k--;
        }

        return ans;
    }
};