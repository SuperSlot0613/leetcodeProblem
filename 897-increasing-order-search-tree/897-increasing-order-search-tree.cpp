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
    vector<int> v;
    void preorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        preorder(root->left);
        v.push_back(root->val);
        preorder(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
       preorder(root);
       TreeNode* newtree=new TreeNode(v[0]);
       TreeNode* current=newtree;
        
       for(int i=1;i<v.size();i++)
       {
            TreeNode* node=new TreeNode(v[i]);
            current->right=node;
            current=current->right;
        }
        
        return newtree;
    }
};