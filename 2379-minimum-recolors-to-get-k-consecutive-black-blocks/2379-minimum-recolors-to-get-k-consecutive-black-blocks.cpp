class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count=0;
        int mini=INT_MAX;

        int left=0 , right =k-1;

        for(int i=0;i<k;i++){
            if(blocks[i]=='W'){
                count++;
            }
        }
        mini=count;
        int n=blocks.size();
        while(right<n-1){
            right++;
            if(blocks[right]=='W'){
                count++;
            }

            if(blocks[left]=='W'){
                count--;
            }
            left++;
            mini=min(mini,count);
        }

        return mini;
    }
};