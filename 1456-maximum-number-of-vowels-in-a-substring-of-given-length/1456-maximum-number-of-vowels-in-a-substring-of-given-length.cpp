class Solution {
public:
    int maxVowels(string s, int k) {
        int count=0 , maxcount=0;
        int left=0 , right=k-1;

        for(int i=0;i<k;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                count++;
            }
        }
        maxcount=count;

        while(right<s.length()-1){
            if(s[left]=='a' || s[left]=='e' || s[left]=='i' || s[left]=='o' || s[left]=='u'){
                count--;
            }
            left++;
            right++;
            if(s[right]=='a' || s[right]=='e' || s[right]=='i' || s[right]=='o' || s[right]=='u'){
                count++;
            }
            maxcount=max(maxcount,count);
        }
        return maxcount;
    }
};