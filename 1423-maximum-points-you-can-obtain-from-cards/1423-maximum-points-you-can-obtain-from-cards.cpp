class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0;
        int l=k-1,  r=n-1;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
    
        int maxsum=sum;

        for(int i=0;i<k;i++){
            sum=sum-cardPoints[l];
            l--;
            sum+=cardPoints[r];
            r--;
            maxsum=max(sum,maxsum);
        }
        return maxsum;
    }
};