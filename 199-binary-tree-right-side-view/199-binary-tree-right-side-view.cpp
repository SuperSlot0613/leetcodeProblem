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
    int maxval=INT_MIN;
    
    void righttreaa(TreeNode* root,int currnode,vector<int>&ans){
        if(root==NULL){
            return;
        }
        if(maxval<currnode){
            maxval=currnode;
            ans.push_back(root->val);
        }
        
        righttreaa(root->right,currnode+1,ans);
        righttreaa(root->left,currnode+1,ans);
        
    }
    
    
    vector<int> rightSideView(TreeNode* root) {
       vector<int> ans;
       righttreaa(root,0,ans);
       return ans;
    }
};