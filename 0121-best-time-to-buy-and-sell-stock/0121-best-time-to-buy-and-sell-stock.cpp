class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Maxprofit=0;
        int n=prices.size();
        int bestBuy=prices[0];
        for(int i=0;i<n;i++){
            if(prices[i]>bestBuy){
                Maxprofit=max(Maxprofit,prices[i]-bestBuy);
            }
            if(bestBuy>prices[i]){
                bestBuy=prices[i];
            }
        }
        return Maxprofit;
    }
};