class KthLargest {
public:
    int k_val;
public:
    KthLargest(int k, vector<int>& nums) {
        k_val=k;
        for(int num:nums){
            add(num);
        }

    }
     priority_queue<int,vector<int> ,greater<int>>h;
    int add(int val) {
       
        h.push(val);

        if(h.size()>k_val){
            h.pop();
        }

        return h.top();

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */