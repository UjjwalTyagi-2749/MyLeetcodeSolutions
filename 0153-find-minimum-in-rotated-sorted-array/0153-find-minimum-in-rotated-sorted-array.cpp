class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int end=nums.size()-1;
        int mid=s+(end-s)/2;
        while(s<end){
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }else{
                end=mid;
            }
            mid=s+(end-s)/2;
        }

        if(nums[0]>nums[s]){
            return nums[s];
        }else{
            return nums[0];
        }
    }
};