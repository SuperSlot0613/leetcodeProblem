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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         if(left==right){
            return head;
        }
        
        ListNode *first,*last,*leftpart,*rightpart;
        leftpart=head;
        rightpart=head;
        int i=1;
        while(i<left){
            first=leftpart;
            leftpart=leftpart->next;
            i++;
        }
        int j=1;
        while(j<right){
            rightpart=rightpart->next;
            j++;
        }
        last=rightpart->next;
        rightpart->next=NULL;
        ListNode *prevnode,*currnode,*nextnode;
        currnode=nextnode=leftpart;
        prevnode=NULL;
        while(nextnode!=NULL){
            nextnode=nextnode->next;
            currnode->next=prevnode;
            prevnode=currnode;
            currnode=nextnode;
        }
        if(first==NULL){
            head=prevnode;
        }else{
         first->next=prevnode;   
        }
        leftpart->next=last;
        return head;
    }
};