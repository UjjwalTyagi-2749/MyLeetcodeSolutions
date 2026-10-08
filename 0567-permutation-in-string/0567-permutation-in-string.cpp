class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>so(26,0);
        vector<int>st(26,0);

        int k=s1.length() , m=s2.length();
        int left=0 , right=k-1;

        if(k>m){
            return false;
        }

        for(int i=0;i<k;i++){
            so[s1[i]-'a']++;
        }

        for(int i=0;i<k;i++){
            st[s2[i]-'a']++;
        }
        if(so==st){
                return true;
            }
        while(right<s2.length()-1){
            
            st[s2[left]-'a']--;
            left++;
            right++;
            st[s2[right]-'a']++;
            if(so==st){
                return true;
            }
        }
        return false;
    }
};