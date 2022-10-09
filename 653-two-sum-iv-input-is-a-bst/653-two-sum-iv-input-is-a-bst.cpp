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
    vector<int> val;
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        val.push_back(root->val);
        inorder(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL){
            return false;
        }
        inorder(root);
        int i=0,j=val.size()-1;
        while(i<j){
            if((val[i]+val[j])>k) j--;
            else if((val[i]+val[j])<k) i++;
            else 
                return true;
        }
        return false;
    }
};