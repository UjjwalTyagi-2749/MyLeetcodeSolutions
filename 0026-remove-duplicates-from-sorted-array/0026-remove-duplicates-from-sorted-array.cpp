class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        for(int i=1;i<n;i++){
            if(nums[l]!=nums[i]){
                l++;
                nums[l]=nums[i];
            }
        }
        return l+1;
    }
};