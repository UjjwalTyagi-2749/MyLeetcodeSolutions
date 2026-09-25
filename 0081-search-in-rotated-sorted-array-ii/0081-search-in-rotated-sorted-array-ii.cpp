class Solution {
public:
    bool answer(vector<int>& nums, int target){
        int s=0;
        int end=nums.size()-1;
        while(s<=end){
            int mid=s+(end-s)/2;
            
            if(nums[mid]==target){
                return true;
            }

            if (nums[s] == nums[mid] && nums[mid] == nums[end]) {
                s++;
                end--;
                continue;
            }

            if(nums[s]<=nums[mid]){
                if(nums[s]<=target && nums[mid]>target){
                    end=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else{
                if(nums[mid]<target && nums[end]>=target){
                    s=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        bool ans=answer(nums,target);
        return ans;
    }
};