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
      TreeNode* findMin(TreeNode* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
    
    TreeNode* findMax(TreeNode* root){
        while(root->right!=NULL){
            root=root->right;
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root,int x){
        if(root==NULL) return root;
        if(x<root->val){
            root->left=deleteNode(root->left,x);
            return root;
        }
        if(x>root->val){
            root->right=deleteNode(root->right,x);
            return root;
        }
        
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        
        if(root->left==NULL){
            TreeNode* temp=root;
            root=root->right;
            delete temp;
            return root;
        }
        
        if(root->right==NULL){
            TreeNode* temp=root;
            root=root->left;
            delete temp;
            return root;
        }
        
        TreeNode* temp=findMin(root->right);
        root->val=temp->val;
        root->right=deleteNode(root->right,temp->val);
        return root;
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL)
        {
            return NULL;
        }
        
        if(root->val >= low && root->val <= high)
        {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }
        else if(root->val > high)
        {
            root = trimBST(root->left, low, high);
        }
        else if(root->val < low){
            root = trimBST(root->right, low, high);
        }
        return root;
    }
};