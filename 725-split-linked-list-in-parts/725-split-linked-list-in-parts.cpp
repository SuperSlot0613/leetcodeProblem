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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*> arr;
        vector<ListNode*> ans(k);
        if(head==NULL){
            return ans;
        }
        ListNode* temp=head;
        while(temp!=NULL){
            arr.push_back(temp);
            temp=temp->next;
        }
        int part=arr.size()/k;
        int extra=arr.size()%k;
        temp=head;
        for(int i=0;i<k && temp!=NULL;i++){
            ans[i] = temp;
            for (int j = 0; j < part + (extra > 0 ? 1 : 0) - 1; j++) temp = temp->next;
            ListNode* temp1 = temp->next;
            temp->next = NULL;
            temp = temp1;
            extra--;
        }
        return ans;
        
        
    }
};