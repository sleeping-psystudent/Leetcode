/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *slow=head, *fast=head;
    for(int i=0;i<n;i++){
        fast=fast->next;
    }
    if(fast==NULL){
        head=slow->next;
        return head;
    }
    while(1){
        if(fast->next==NULL){
            slow->next=slow->next->next;
            return head;
        }
        else{
            slow=slow->next;
            fast=fast->next;
        }
    }
}
