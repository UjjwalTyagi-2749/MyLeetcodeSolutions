class Solution {
public:
    int solve(vector<int>& coins, int n){
        if(n==0){
            return 0;
        }
        if(n<0){
            return INT_MAX;
        }
        int ans=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(n-coins[i]>=0){
                int sub=solve(coins,n-coins[i]);
                if(sub!=INT_MAX){
                    sub=sub+1;
                    ans=min(ans,sub);
                }
                
            }
        }
        return ans;
    }

    int solvememo(vector<int>& coins, int n,vector<int>&dp){
        if(n==0){
            return 0;
        }
        if(n<0){
            return INT_MAX;
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        int ans=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(n-coins[i]>=0){
                int sub=solvememo(coins,n-coins[i],dp);
                if(sub!=INT_MAX){
                    sub=sub+1;
                    ans=min(ans,sub);
                }
                
            }
        }
        dp[n]=ans;
        return dp[n];
    }

    int coinChange(vector<int>& coins, int amount) {
        // int ans=solve(coins,amount);
        // if(ans==INT_MAX){
        //     return -1;
        // }
        // else {
        //     return ans;
        // }
        int n=coins.size();
        vector<int>dp(amount+1,-1);
        int ans=solvememo(coins,amount,dp);
        if(ans==INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};