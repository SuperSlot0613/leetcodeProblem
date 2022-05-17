/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    
    void preorder(TreeNode* root,TreeNode* target){
        if(root==NULL) return;
        if(root->val==target->val){
            ans=root;
        }
        preorder(root->left,target);
        preorder(root->right,target);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        preorder(cloned,target);
        return ans;
    }
};