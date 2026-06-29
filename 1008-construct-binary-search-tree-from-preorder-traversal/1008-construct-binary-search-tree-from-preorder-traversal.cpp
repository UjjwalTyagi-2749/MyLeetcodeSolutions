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
    TreeNode*ppreorder(TreeNode*root,int data){
        if(root==NULL){
            root=new TreeNode(data);
            return root;
        }
        if(root->val<data){
            root->right=ppreorder(root->right,data);
        }else{
            root->left=ppreorder(root->left,data);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode*root=NULL;
        int n=preorder.size();
        for(int i=0;i<n;i++){
            root=ppreorder(root,preorder[i]);
        }
        return root;
    }
};