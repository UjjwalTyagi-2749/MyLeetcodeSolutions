class Solution {
public:
    int solve(int n,vector<int>&dp,vector<int>& cost){
        if(n==0){
            return cost[0];
        }
        int prev1=cost[1];
        int prev2=cost[0];
        int curr;   
        for(int i=2;i<=n;i++){
            curr=cost[i]+min(prev1,prev2);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        int ans=min(solve(n-1,dp,cost),solve(n-2,dp,cost));
        return ans;
    }
};