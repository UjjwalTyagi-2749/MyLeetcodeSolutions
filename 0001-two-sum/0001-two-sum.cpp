class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int fe=nums[i];
            for(int j=i+1;j<n;j++){
                int se=nums[j];
                if(se+fe==target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};