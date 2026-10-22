class Solution {
public:
    int solveMemoization(vector<int>& nums,int n,vector<int>& dp){
        if(n<0){
            return 0;
        }

        if(n==0){
            nums[0];
        }
        if(dp[n]!=-1){
            return dp[n];
        }

        int in=solveMemoization(nums,n-2,dp)+nums[n];
        int ex=solveMemoization(nums,n-1,dp)+0;

        return dp[n]=max(in ,ex);
    }

    int solveTabulation(vector<int>& nums){
        int n=nums.size();
        vector<int>dp(n,0);
        if(n==0){
            return 0;
        }

        if(n==1){
            return nums[0];
        }

        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int in=dp[i-2]+nums[i];
            int ex=dp[i-1]+0;
            dp[i]=max(in,ex);
        }
        return dp[n-1];
    }

    int solvetwo(vector<int>&nums){
        int n=nums.size();
        int prev2=0;
        int prev1=nums[0];

        for(int i=1;i<n;i++){
            int in=prev2+nums[i];
            int ex=prev1+0;

            int ans=max(in,ex);
            prev2=prev1;
            prev1=ans;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        // return solveMemoization(nums,n-1,dp);
        // return solveTabulation(nums);
        return solvetwo(nums);
    }
};