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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        while(root!=NULL){
            st.push(root);
            root=root->left;     
        }
        
        while(not st.empty()){
            root=st.top();
            st.pop();
            ans.push_back(root->val);
            root=root->right;
            while(root!=NULL){
               st.push(root);
               root=root->left;
            }
        }
        
        return ans;
    }
};