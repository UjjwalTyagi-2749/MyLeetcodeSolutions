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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int lastval;
        queue<TreeNode*>q;

        if(root==NULL){
            return ans;
        }
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode*temp=q.front();
            q.pop();
            if(temp!=NULL){
                lastval=temp->val;
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            else if(!q.empty()){
                q.push(NULL);
                ans.push_back(lastval);
            }
            else{
                ans.push_back(lastval);
            }
        }
        return ans;
    }
};