class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>h;
        int n=score.size();
        for(int i=0;i<n;i++){
            h.push({score[i],i});
        }

        vector<string>ans(n);

        int rank=1;

        while(!h.empty()){
            auto top=h.top();
            h.pop();
            int index=top.second;

            if(rank==1){
                ans[index]="Gold Medal";
            }
            else if(rank==2){
                ans[index]="Silver Medal";
            }
            else if(rank==3){
                ans[index]="Bronze Medal";
            }
            else{
                ans[index]=to_string(rank);
            }
            rank++;
        }
            return ans;
    }
};