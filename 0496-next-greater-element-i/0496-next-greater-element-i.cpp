class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        stack<int>s;
        unordered_map<int,int>M;

        for(int i=0;i<nums2.size();i++){

            while(!s.empty() && s.top()<nums2[i]){
                M[s.top()]=nums2[i];
                s.pop();
            }

            s.push(nums2[i]);
        }

        while(!s.empty()){
            M[s.top()]=-1;
            s.pop();
        }

        for(int i=0;i<nums1.size();i++){
            ans.push_back(M[nums1[i]]);
        }

        return ans;
    }
};