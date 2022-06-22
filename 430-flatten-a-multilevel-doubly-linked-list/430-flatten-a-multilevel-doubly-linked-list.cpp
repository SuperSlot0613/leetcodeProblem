/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* fun(Node* head)
    {
        Node* ptr=head;
        Node* prevv=head;
       while(ptr!=NULL)
        {
            if(ptr->child==NULL)
            {
                prevv=ptr;
                ptr=ptr->next;
            }
            else
            {
                Node* nextt;
                if(ptr->next)
                    nextt=ptr->next;
                else
                    nextt=ptr->child;
                ptr->next=ptr->child;
                ptr->child->prev=ptr;
                Node* end=NULL;
                if(ptr->next!=nextt)
                    end=fun(ptr->child);
                ptr->child=NULL;
                if(ptr->next!=nextt){
                    end->next=nextt;
                    nextt->prev=end;
                }
            }
        }
        return prevv;
    }
    Node* flatten(Node* head) {
        if(!head)
            return head;
        
        Node* ptr=head;
        
        while(ptr!=NULL)
        {
            if(ptr->child==NULL)
            {
                ptr=ptr->next;
            }
            else
            {
                Node* nextt;
                if(ptr->next)
                    nextt=ptr->next;
                else
                    nextt=ptr->child;
                ptr->next=ptr->child;
                ptr->child->prev=ptr;
                Node* end=NULL;
                if(ptr->next!=nextt)
                    end=fun(ptr->child);
                ptr->child=NULL;
                if(ptr->next!=nextt){
                    end->next=nextt;
                    nextt->prev=end;
                }
            }
        }
        return head;
    }
};