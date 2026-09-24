class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
       
       
        unordered_set<char>se;
        int maxlen=0;
        while(r<s.length()){
            if(se.find(s[r])!=se.end()){
                while(l<=r && se.find(s[r])!=se.end()){
                    se.erase(s[l]);
                    l++;

                }
            }else{
                se.insert(s[r]);
                r++;
            }
            maxlen=max(maxlen,r-l);
        }
        return maxlen;
    }
};