class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0;
        int right=0;
        int zero=0;
        int ans=0;

        while(right<nums.size()){
           
            if(nums[right]==0){
                zero++;
            }
            right++;


            if(zero>1){
                if(nums[left]==0){
                    zero--;
                    
                }
                left++;
            }
            ans=max(ans,right-left);
        }
        return ans-1;
    }
};