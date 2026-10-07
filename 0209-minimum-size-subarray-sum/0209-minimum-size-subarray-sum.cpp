class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0 , right=0;
        int minlen=INT_MAX;
        int sum=0;

        while(right<nums.size()){
            sum+=nums[right];
            right++;
            
            while(sum>=target){
                minlen=min(minlen,right-left);
                sum-=nums[left];
                left++;
            }
        }
        if(minlen == INT_MAX){
            return 0;
        }
        else{
            return minlen;
        }
        
    }
};