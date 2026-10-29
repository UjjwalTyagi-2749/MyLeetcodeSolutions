class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>h(gifts.begin(),gifts.end());

        for(int i=0;i<k;i++){
            int x=h.top();
            h.pop();

            h.push(sqrt(x));
        }

        long long ans=0;

        while(!h.empty()){
            ans+=h.top();
            h.pop();
        }

        return ans;
    }
};