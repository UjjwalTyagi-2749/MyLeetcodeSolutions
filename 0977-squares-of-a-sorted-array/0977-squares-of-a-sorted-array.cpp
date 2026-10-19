class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);

        int l=0 , r=n-1;
        int i=n-1;
        while(l<=r){
            if(abs(nums[l])<abs(nums[r])){
                res[i]=nums[r]*nums[r];
                r--;
            }else{
                res[i]=nums[l]*nums[l];
                l++;
            }
            i--;
        }
        return res;

    }
};