//2023/07/07
//開一條新的，把每條中較小的接上去
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* now;
    struct ListNode* head;
    int i=0;
    while(1){
        if(list1==NULL && list2==NULL) return head;
        else if(list1==NULL || (list2!=NULL && list1->val>list2->val)){
            if(i==0){
                head=list2;
                now=list2;
                list2=list2->next;
                i++;
            }
            else{
                now->next=list2;
                now=now->next;
                list2=list2->next;
            }
        }
        else if(list2==NULL || (list1!=NULL && list1->val<=list2->val)){
            if(i==0){
                head=list1;
                now=list1;
                list1=list1->next;
                i++;
            }
            else{
                now->next=list1;
                now=now->next;
                list1=list1->next;
            }
        }
    }
}
