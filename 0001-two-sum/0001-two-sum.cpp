class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }

        for(int i=0;i<nums.size();i++){
            int val=target-nums[i];
            if(m.find(val)!=m.end() && m[val]!=i){
                ans.push_back(i);
                ans.push_back(m[val]);
                return ans;
            }
        }
        return ans;
    }
};