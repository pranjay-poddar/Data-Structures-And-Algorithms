/* You are given two linked lists list1, list2 of size n amd m respectively.
   Remove ath to bth node of list1 and insert list2 in their place.
*/

/* Example 1:
   Input : list1 = [0, 1, 2, 3, 4, 5], a=3, b=4, list2 = [10, 20, 30]
   Output : [0, 1, 2, 10, 20, 30, 5]
*/

/* Example 2:
   Input : list1 = [1, 2, 3, 4, 5, 6], a=2, b=4, list2 = [100, 200, 300]
   Output : [1, 2, 100, 200, 300, 6]
*/

/*
  Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode *temp=list1,*temp1,*temp2;
    int i;
    for(i=0;i<a-1;i++)
        temp=temp->next;
    temp1=temp;
    for(;i<=b;i++)
        temp=temp->next;
    temp2=temp;
    temp1->next=list2;
    while(list2->next!=NULL)
        list2=list2->next;
    list2->next=temp2;
    return list1;
}
