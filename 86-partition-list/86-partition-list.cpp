/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        struct ListNode *head2,*temp,*ptr,*head3,*larg;
        temp=head;
        head2=NULL;
        head3=NULL;
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }
        while(temp!=NULL){
            if(head2==NULL and temp->val<x){
                head2=ptr=temp;
            }
            else if(temp->val < x){
                ptr->next=temp;
                ptr=temp;
            }
            else{
                if(head3==NULL){
                    head3=larg=temp;
                }
                else{
                    larg->next=temp;
                    larg=temp;
                }
            }
            temp=temp->next;
        }
        if(head2==NULL){
           return head3;
        }
        else{
            if(head3!=NULL){
                larg->next=NULL;
                ptr->next=head3;
            }
            else{
                ptr->next=head3;
            }
        }
        return head2;
        
    }
};