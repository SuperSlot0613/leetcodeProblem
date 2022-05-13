/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
     void level_order_levelwise(Node* root){
        if(root==NULL);
        queue<Node*> qu;
        qu.push(root);
        qu.push(NULL);
        while(not qu.empty()){
            if(qu.front()==NULL){
                qu.pop();
                if(qu.size()==0) break;
                qu.push(NULL);
                continue;
            }
            Node* curr=qu.front();
            qu.pop();
            Node* second=qu.front();
            curr->next=second;
            if(curr->left){
                qu.push(curr->left);
            }
            if(curr->right){
                qu.push(curr->right);
            }
        }
    }
    
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        level_order_levelwise(root);
        return root;
    }
};