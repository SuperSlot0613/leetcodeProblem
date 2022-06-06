/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = 0 , sizeB = 0;
        ListNode* temp;
        
        temp = headA;
        while( temp ){ sizeA++; temp=temp->next; }
        
        temp = headB;
        while( temp ){ sizeB++; temp=temp->next; }
        
        int val = 0;
        while( headA ){
            if( sizeA > sizeB ){
                sizeA--;
                headA = headA->next;
            }else if( sizeB > sizeA ){
                sizeB--;
                headB = headB->next;
            }else{
                if( headA == headB ){
                    return headA;
                }
                headA = headA->next;
                headB = headB->next;
            }
        }
        
        return NULL;
    }
};