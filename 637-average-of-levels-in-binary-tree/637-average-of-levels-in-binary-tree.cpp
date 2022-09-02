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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        vector<long long> temp;
        queue<TreeNode*> qe;
        qe.push(root);
        qe.push(NULL);
        ans.push_back(root->val);
        while(!qe.empty()){
            if(qe.front()==NULL){
                qe.pop();
                double sum=0.00000;
                sum=accumulate(temp.begin(),temp.end(),sum);
                if(temp.size()!=0){
                  ans.push_back((double)(sum)/temp.size());
                  temp.clear();
                }
                if(qe.size()==0) break;
                qe.push(NULL);
                continue;
            }
            
            TreeNode* curr=qe.front();
            qe.pop();
            if(curr->left){
                qe.push(curr->left);
                temp.push_back(curr->left->val);
            }
            if(curr->right){
                qe.push(curr->right);
                temp.push_back(curr->right->val);
            }
        }
        return ans;
    }
};