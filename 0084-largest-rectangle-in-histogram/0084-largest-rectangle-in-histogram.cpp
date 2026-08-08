class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>s;
        vector<int>left(n),right(n);

        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>heights[i]){
                s.pop();
            }
            if(s.empty()){
                left[i]=i+1;
            }else{
                left[i]=i-s.top();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        };

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                right[i]=n-i;
            }else{
                right[i]=s.top()-i;
            }
            s.push(i);
        }

        int sum=0;
        int maxsum=0;
        for(int i=0;i<n;i++){
            sum=heights[i]*(left[i]+right[i]-1);
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
};