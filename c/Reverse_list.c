/*You are given a linked list and two integers left and right (left<=right)
  you have to reverse the list from position left to right, and 
  return the reversed linked list*/

/* Example 1:

   Input: head=[1, 2, 3, 4, 5], left=2, right=4
   Output: [1, 4, 3, 2, 5]
*/

/* Example 2:

   Input: head=[1, 3, 4, 7, 8, 2, 9], left=3, right=5
   Output: [1, 3, 8, 7, 4, 2, 9]
*/

/*
  Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
*/


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if(head==NULL)
        return NULL;
    struct ListNode *cur=head,*prev=NULL;
    while(m>1)
    {
        prev=cur;
        cur=cur->next;
        m--;
        n--;
    }
    struct ListNode *con=prev,*tail=cur,*next=NULL;
    while(n>0)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        n--;
    }
    if(con!=NULL)
        con->next=prev;
    else
        head=prev;
    tail->next=cur;
    return head;
}
