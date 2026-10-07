class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0 , right=0;
        int zero=0 , maxlen=INT_MIN;
        
        
        while(right<nums.size()){
            if(nums[right]==0){
                zero++;
            }
            right++;
            while(zero>k){
                if(nums[left]==0){
                    zero--;
                }
                left++;
               
            }
            maxlen=max(maxlen,right-left);
        }
        return maxlen;
    }
};