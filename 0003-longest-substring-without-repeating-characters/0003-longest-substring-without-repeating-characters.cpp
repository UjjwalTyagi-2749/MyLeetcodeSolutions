class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>map;
        int l=0;
        int r=0;
        int maxLen=0;
        while(r<s.size()){
            if(map.find(s[r])!=map.end()){
                l=max(l,map[s[r]]+1);
                map[s[r]]=r;
            }else{
               map[s[r]]=r; 
            }
            maxLen=max(maxLen , r-l+1);
            r++;
        }
        return maxLen;
    }
};