class Solution {
public:
    bool alphanumeric(char c){
        if((c>='0' && c<='9' )|| (c>='a' && c<='z')|| (c>='A' && c<='Z')){
            return true;
        }
         
        return false;
    }
    bool isPalindrome(string s) {
        int n=s.length();
        int l=0 , r=n-1;

        while(l<=r){
            if(!alphanumeric(s[l])){
                l++;
                continue;
            }
            if(!alphanumeric(s[r])){
                r--;
                continue;
            }

            if(tolower(s[l])!=tolower(s[r])){
                return false;
            }

            l++ ;
            r--;
        }
        return true;
    }
};