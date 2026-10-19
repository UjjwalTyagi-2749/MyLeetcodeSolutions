class Solution {
public:
    bool vowel(char c){
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string reverseVowels(string s) {
        int n=s.length();
        int l=0, r=n-1;

        while(l<r){
            
            if(!vowel(s[l])){
                while(!vowel(s[l]) && (l < r)){
                    l++;
                }
            }
            if(!vowel(s[r])){
                while(!vowel(s[r]) && (l < r)){
                    r--;
                }
            }

            if(l<r){
swap(s[l],s[r]);
            l++;
            r--;
            }
            
        }
        return s;
    }
};