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
     void helper(TreeNode* root, vector<vector<int>>& res, vector<int> cur, int curSum, int target) {
        if(!root->left && !root->right) {
            if(curSum+root->val == target) {
                cur.push_back(root->val);
                res.push_back(cur);
            }
            return;
        }
        cur.push_back(root->val);
        if(root->left) helper(root->left, res, cur, curSum+root->val, target);
        if(root->right) helper(root->right, res, cur, curSum+root->val, target);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<vector<int>> res;
        vector<int> cur;
        helper(root, res, cur, 0, targetSum);
        return res;
    }
};