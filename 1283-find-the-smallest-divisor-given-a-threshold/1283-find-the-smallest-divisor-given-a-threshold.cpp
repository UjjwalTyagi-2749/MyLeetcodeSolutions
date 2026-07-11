class Solution {
public:
    bool isless(vector<int>& nums,int mid, int threshold){
        int val=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            val+=nums[i]/mid;
            if(nums[i]%mid!=0){
            val++;
        }
        }
        
        
        return val<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        int n=nums.size();
        int l=1 , r=*max_element(nums.begin(),nums.end());
        int mid=l+(r-l)/2;

        while(l<r){
            if(isless(nums,mid,threshold)){
                r=mid;
            }else{
                l=mid+1;
            }
            mid=l+(r-l)/2;
        }
        return mid;
    }
};