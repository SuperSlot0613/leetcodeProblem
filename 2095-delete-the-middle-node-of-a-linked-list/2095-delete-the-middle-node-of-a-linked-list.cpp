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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL){
            return NULL;
        }
        int n=0;
        ListNode* temp;
        temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int del=n/2;
        int i=0;
        temp=head;
        while(i<del-1){
            temp=temp->next;
            i++;
        }
        ListNode* delet=temp->next;
        temp->next=delet->next;
        return head;
    }
};