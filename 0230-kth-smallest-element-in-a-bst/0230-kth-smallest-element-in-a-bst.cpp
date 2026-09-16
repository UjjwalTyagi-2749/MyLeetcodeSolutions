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
    void inorder(TreeNode*root ,int k,int &ans,int & i){

        if(root==NULL){
            return;
        }

        inorder(root->left,k,ans,i);

        i++;
        if(i==k){
            ans=root->val;
        }

        inorder(root->right,k,ans,i);

    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        int i=0;
        inorder(root,k,ans,i);
        return ans;
    }
};