//2023/07/07
//多個sorted ll，先將所有元素都丟進一個N*k大小的array做min-heap，接著一直取heap最頂端的元素（array[0]）加進新的ll中
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void swap(int *a,int *b){
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(int array[],int size,int i){
  if (size>1){
    int smallest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<size && array[l]<array[smallest]) smallest=l;
    if(r<size && array[r]<array[smallest]) smallest=r;
    if (smallest!=i){
      swap(&array[i],&array[smallest]);
      heapify(array,size,smallest);
    }
  }
}

void deleteRoot(int array[],int size){
  swap(&array[0],&array[size-1]);
  for(int i=(size-1)/2-1;i>=0;i--) heapify(array,size-1,i);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int i,j;
    if(listsSize==0) return NULL;
    int heap[listsSize*500];
    int end=0;
    for(i=0;i<listsSize;i++){
        while(lists[i]!=NULL){
            heap[end++]=lists[i]->val;
            lists[i]=lists[i]->next;
            for(j=end/2-1;j>=0;j--) heapify(heap,end,j);
        }
    }
    if(end==0) return NULL;

    struct ListNode* head;
    struct ListNode* now;
    i=0;
    while(end!=0){
      struct ListNode* new=malloc(sizeof(struct ListNode));
      new->val=heap[0];
      new->next=NULL;
      if(i==0){
          head=new;
          now=new;
          i++;
      }
      else{
          now->next=new;
          now=now->next;
      }
      deleteRoot(heap,end);
      end--;
    }
    return head;
}
