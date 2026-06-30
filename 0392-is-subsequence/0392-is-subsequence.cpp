class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l=0;
        int r=0;
        int c=0;
        int count =t.size();
        while(r<count){
            if(s[l]==t[r]){
                l++;
                r++;
                c++;
            }else{
                r++;
            }
        }
        if(c==s.size()){
            return true;
        }else{
            return false;
        }
    }
};