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
class BSTIterator {
public:
    vector<int> inorder;
    int k=0,n;
    void inorderT(TreeNode *root)
    {
        if(!root)   return;
        inorderT(root->left);
        inorder.push_back(root->val);
        inorderT(root->right);
    }
    BSTIterator(TreeNode* root) {
        inorderT(root);
        n = inorder.size();
    }
    int next() {
        if(k<n)     return inorder[k++];
        return -1;
    }
    bool hasNext() {
        if(k<n)   return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */