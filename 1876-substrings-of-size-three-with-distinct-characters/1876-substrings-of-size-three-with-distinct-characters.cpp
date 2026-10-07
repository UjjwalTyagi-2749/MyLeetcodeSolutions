class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<int,int>us;
        int left=0 , right=2;
        int count=0 , maxcount=0;

        if(s.length()<3){
            return 0;
        }
        for(int i=0;i<3;i++){
            us[s[i]]++;
        }
        if(us.size()==3){
            count++;
        }
        maxcount=count;

        while(right<s.length()-1){
            us[s[left]]--;
            if(us[s[left]]==0){
                us.erase(s[left]);
            }
            left++;
            right++;
            us[s[right]]++;
            if(us.size()==3){
            count++;
        }
        maxcount=max(maxcount,count);
        }
        return maxcount;
    }
};