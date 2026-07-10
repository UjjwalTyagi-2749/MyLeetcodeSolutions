class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int n1=nums1.size();
        int n2=nums2.size();
        int N=(n1+n2);
        int st=0;
        int end=n1;
        while(st<=end){
            int cut1=st+(end-st)/2;
            int cut2=N/2-cut1;
            int l1;
            int l2;
            if(cut1==0){
                l1=INT_MIN;
            }
            else{
                l1=nums1[cut1-1];
            }
            if(cut2==0){
                l2=INT_MIN;
            }
            else{
                l2=nums2[cut2-1];
            }
            int r1;
            int r2;
            if(cut1==n1){
                r1=INT_MAX;
            }
            else{
                r1=nums1[cut1];
            }
            if(cut2==n2){
                r2=INT_MAX;
            }
            else{
                r2=nums2[cut2];
            }

            if(l1<=r2 && l2<=r1){
                if(N%2!=0){
                    return min(r1,r2);
                }
                else{
                    return((double)(max(l1,l2)+min(r1,r2))/2);
                }
            }
            else if(l1>r2){
                end=cut1-1;
            }
            else{
                st=cut1+1;
            }
        }
        return 0.0;
    }
};