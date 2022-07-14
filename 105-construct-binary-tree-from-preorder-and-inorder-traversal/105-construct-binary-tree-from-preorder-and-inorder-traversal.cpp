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
     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        std::map<int, int> imap;

        for(int i=0;i<inorder.size();i++){
            imap[inorder[i]]=i;
        }

      TreeNode*                           root=BuildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,imap);

        return root;
        
    }
    TreeNode* BuildTree(vector<int> &preorder,int prestart,int preend,
        vector<int> &inorder,int instart,int inend,map<int, int> &imap){

        if(prestart>preend || instart>inend) return NULL;

        TreeNode* root=new TreeNode(preorder[prestart]);
        int inRoot=imap[root->val];
        int numleft=inRoot-instart;

        root->left=BuildTree(preorder,prestart+1,prestart+numleft,inorder,instart,inRoot-           1,imap);
        root->right=BuildTree(preorder,prestart+numleft+1,
                    preend,inorder,inRoot+1,inend,imap);

        return root;

    }
};