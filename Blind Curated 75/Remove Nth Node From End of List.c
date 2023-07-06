//2023/07/06
//一個慢指標，一個快指標
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* now=head;
    struct ListNode* predel=head;
    int i=0;
    while(now!=NULL){
        if(i>n) predel=predel->next;
        now=now->next;
        i++;
    }
    if(i<=n) head=predel->next;
    else predel->next=predel->next->next;
    return head;
}
