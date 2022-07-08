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
     TreeNode * BinaryBST(vector<int>&nums,int si,int ei){
        if(si>ei) return NULL;
        int mid = (si+ei)/2;
        TreeNode * root = new TreeNode(nums[mid]);
        TreeNode * leftSide = BinaryBST(nums,si,mid-1);
        TreeNode * rightSide = BinaryBST(nums,mid+1,ei);
        root->left = leftSide;
        root->right = rightSide;
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len=nums.size()-1;
        return BinaryBST(nums,0,len);
        
    }
};