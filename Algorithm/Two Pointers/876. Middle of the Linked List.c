/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *slow=head, *fast=head;
    while(1){
        if(fast==NULL||fast->next==NULL) return slow;
        else{
            slow=slow->next;
            fast=fast->next->next;
        }
    }
}
