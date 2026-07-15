class Solution {
public:
    int BinarySearch(vector<int>& nums, int target,bool first){
        int s=0;
        int end=nums.size()-1;
        int mid=s+(end-s)/2;
        int ans=-1;
        while(s<=end){
            if(nums[mid]==target){
                ans=mid;
                if(first){
                    end=mid-1;
                }else{
                    s=mid+1;
                }
            }
            if(nums[mid]<target){
                s=mid+1;
            }
            if(nums[mid]>target){
                end=mid-1;
            }
            mid=s+(end-s)/2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>answer;
        int first=BinarySearch(nums,target,true);
        int second=BinarySearch(nums,target,false);
        answer.push_back(first);
        answer.push_back(second);
        return answer;
    }
};