class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left=0 , right=k-1;
        int count=0;
        int sum=0;
        
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        if(sum/k>=threshold){
            count++;
        }
        while(right<arr.size()-1){
            sum-=arr[left];
            left++;
            right++;
            sum+=arr[right];
            if(sum/k>=threshold){
            count++;
            }
        }
        return count;
    }
};