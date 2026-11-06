class Solution {
public:
    int answer(vector<int>& nums, int target,bool first){
        int s=0;
        int end=nums.size()-1;
        int ans=-1;
        while(s<=end){
            int mid=s+(end-s)/2;
            if(nums[mid]==target){
                ans=mid;

                if(first){
                    end=mid-1;
                }
                else{
                    s=mid+1;
                }
            }

            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        ans.push_back(answer(nums,target,true));
        ans.push_back(answer(nums,target,false));
        return ans;
    }
};