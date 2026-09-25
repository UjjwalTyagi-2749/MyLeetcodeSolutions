class Solution {
public:
    int value(vector<int>& nums){
        int s=0;
        int end=nums.size()-1;
        while(s<end){
            int mid=s+(end-s)/2;

            if(nums[mid]>nums[end]){
                s=mid+1;
            }
            else{
                end=mid;
            }
        }
        return nums[s];
    }
    int findMin(vector<int>& nums) {
       return value(nums); 
    }
};