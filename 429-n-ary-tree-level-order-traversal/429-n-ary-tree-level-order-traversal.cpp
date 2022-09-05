/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> ans;
    void levelOrderTravel(Node* root){
        if(root==NULL){
            return;
        }
        vector<int> temp;
        queue<Node*> node;
        node.push(root);
        node.push(NULL);
        while(!node.empty()){
            if(node.front()==NULL){
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                temp.clear();
                node.pop();
                if(node.size()==0) break;
                node.push(NULL);
                continue;
            }
            Node* curr=node.front();
            temp.push_back(curr->val);
            node.pop();
            vector<Node*>::iterator it = curr->children.end();
            while(it!=curr->children.begin()){
                it--;
                node.push(*it);
            }
            
        }
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        levelOrderTravel(root);
        return ans;
    }
};