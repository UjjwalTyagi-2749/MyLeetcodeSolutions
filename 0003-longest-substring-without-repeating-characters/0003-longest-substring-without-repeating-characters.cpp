class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0 , right=0;
        unordered_map<char,int>m;
        int maxlen=INT_MIN;

        if(s.length()==0){
            return 0;
        }

        while(right<s.length()){
            m[s[right]]++;
            right++;
            while(right-left>m.size()){
               m[s[left]]--;
               if(m[s[left]]==0){
                m.erase(s[left]);
               }
               left++; 
            }
            maxlen=max(maxlen,right-left);
        }
        return maxlen;
    }
};