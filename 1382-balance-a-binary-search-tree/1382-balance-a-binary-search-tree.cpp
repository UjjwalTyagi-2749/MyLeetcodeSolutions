/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode*root,vector<int>&ans){
        if(root==NULL){
            return;
        }

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }

    TreeNode* inordertobst(int st,int end,vector<int>ans){
        if(st>end){
            return NULL;
        }

        int mid=st+(end-st)/2;

        TreeNode*curr=new TreeNode(ans[mid]);
        curr->left=inordertobst(st,mid-1,ans);
        curr->right=inordertobst(mid+1,end,ans);
        return curr;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        return inordertobst(0,ans.size()-1,ans);
    }
};