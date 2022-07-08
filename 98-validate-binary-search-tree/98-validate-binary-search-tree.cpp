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
    bool checkValid(TreeNode* root,long long right,long long left)
    {
        if(root==NULL)
            return true;     
        if(root->val<right&&root->val>left)
                return (checkValid(root->left,root->val,left)&&
                        checkValid(root->right,right,root->val));   
        else
           return false;
        
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root->left&&!root->right)    //if only singe node is there
            return true;
        return checkValid(root,LONG_MAX,LONG_MIN);
        
    }
};