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
    TreeNode* first=nullptr;
    TreeNode* second=nullptr;
    TreeNode* pre=new TreeNode(INT_MIN);
    void recoverTree(TreeNode* root) {
        recur(root);
        int t=first->val;
        first->val=second->val;
        second->val=t;
    }
    void recur(TreeNode* root)
    {
        if(root)
        {
            recur(root->left);
            if(root->val<pre->val)
            {
                if(first!=nullptr)
                    second=root;
                else
                {
                    first=pre;
                    second=root;                    
                }
            }
            pre=root;
            recur(root->right);
        }
    }
};