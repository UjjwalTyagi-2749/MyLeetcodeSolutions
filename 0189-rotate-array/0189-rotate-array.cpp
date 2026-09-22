class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        int r=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+r);
        reverse(nums.begin()+r,nums.end());
    }
};