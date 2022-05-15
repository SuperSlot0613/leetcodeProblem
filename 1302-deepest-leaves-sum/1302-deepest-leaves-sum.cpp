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
    int sum=0;
    int Height(TreeNode* root){
        int hl,hr;
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 0;
        }
        hl=Height(root->left);
        hr=Height(root->right);
        if(hl>hr){
            return (hl+1);
        }
        return (hr+1);
        
    }
    
    void preorder(TreeNode* root,int i,int depth){
         if(root==NULL){
            return;
        }
        if(i==depth){
            sum=sum+root->val;
            return;
        }
        preorder(root->left,i+1,depth);
        preorder(root->right,i+1,depth);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        if(root->left==NULL && root->right==NULL){
            return root->val;
        }
        int depth=Height(root);
        preorder(root,0,depth);
        return sum;
    }
};