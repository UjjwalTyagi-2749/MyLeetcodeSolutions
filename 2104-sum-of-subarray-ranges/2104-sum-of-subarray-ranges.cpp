class Solution {
public:
    long long max(vector<int>& nums){
        int n=nums.size();
        vector<int>left(n),right(n);
        stack<int>s;

        for(int i=0;i<n;i++){

            while(!s.empty() && nums[s.top()]<nums[i]){
                s.pop();
            }
            if(s.empty()){
                left[i]=i+1;
            }
            else{
                left[i]=i-s.top();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();

        for(int j=n-1;j>=0;j--){

            while(!s.empty() && nums[s.top()]<=nums[j]){
                s.pop();
            }
            if(s.empty()){
                right[j]=n-j;
            }
            else{
                right[j]=s.top()-j;
            }
            s.push(j);
        }
        long long sum=0;

        for(int i=0;i<n;i++){
            sum+=(long long )nums[i]*left[i]*right[i];
        }
        return sum;
    }

    long long min(vector<int>& nums){
        int n=nums.size();
        vector<int>left(n),right(n);
        stack<int>s;
        

        for(int i=0;i<n;i++){

            while(!s.empty() && nums[s.top()]>nums[i]){
                s.pop();
            }
            if(s.empty()){
                left[i]=i+1;
            }
            else{
                left[i]=i-s.top();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();

        for(int j=n-1;j>=0;j--){

            while(!s.empty() && nums[s.top()]>=nums[j]){
                s.pop();
            }
            if(s.empty()){
                right[j]=n-j;
            }
            else{
                right[j]=s.top()-j;
            }
            s.push(j);
        }
        long long sum=0;

        for(int i=0;i<n;i++){
            sum+=(long long)nums[i]*left[i]*right[i];
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long mini=min(nums);
        long long maxi=max(nums);
        return maxi-mini;
    }
};