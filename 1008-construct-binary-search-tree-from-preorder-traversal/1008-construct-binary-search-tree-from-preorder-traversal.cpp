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
     TreeNode* Treeformation(TreeNode* root,int val){
        
        if(root==NULL){
            root=new TreeNode(val);
            return root;
        }
        
        if(val>root->val){
            root->right=Treeformation(root->right,val);
            return root;
        }
        
        root->left=Treeformation(root->left,val);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=NULL;
        for(int i=0;i<preorder.size();i++){
            root=Treeformation(root,preorder[i]);
        }
        return root;
    }
};