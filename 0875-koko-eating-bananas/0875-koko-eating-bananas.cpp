class Solution {
public:
    bool canEatAll(vector<int>& piles,int mid, int h){
        int actualHour=0;
        for(int i=0;i<piles.size();i++){
            actualHour+=piles[i]/mid;
            if(piles[i]%mid!=0){
                actualHour+=1;
            }
        }
        return actualHour<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l= 1 , r=*max_element(piles.begin(),piles.end());
        int mid=l+(r-l)/2;

        while(l<r){
            if(canEatAll(piles,mid,h)){
                r=mid;
            }else{
                l=mid+1;
            }
            mid=l+(r-l)/2;
        }
        return l;
    }
};