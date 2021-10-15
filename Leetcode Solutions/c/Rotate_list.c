//You are given the head of a linked list, rotate the list to the right by k places.

/* Example 1:
   Input : head=[1, 2, 3, 4, 5], k=2
   Output : [4, 5, 1, 2, 3]
*/

/* Example 2:
   Input : head=[0, 1, 2], k=4
   Output : [2, 0, 1]
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if(!head)
        return head;
    struct ListNode *temp=head,*new;
    int len=1;
    while(temp->next!=NULL)
    {
        len++;
        temp=temp->next;
    }
    temp->next=head;
    if(k%=len)
    {
        for(int i=0;i<len-k;i++)
            temp=temp->next;
    }
    new=temp->next;
        temp->next=NULL;
        return new;
}
