// You are given the head of a linked list and Nth node from the end of the list.

// Delete the Nth node and return the updated linked list.

/* Example 1 
    Input : head=[1, 2, 3, 4, 5]
    n=2
    Output : [1, 2, 3, 5]
*/

/* Example 2 
    Input : head=[2, 4, 6, 1, 5, 2 ,4]
    n=4
    Output : [2, 4, 6, 5, 2, 4]
*/

 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int i=0;
    struct ListNode *temp=head;
    if(head->next==NULL)
        return NULL;
    while(temp!=NULL)
    {
        i++;
        temp=temp->next;
    }
    if(i==n)
        return head->next;
    i=i-n-1;
    temp=head;
    while(i>0)
    {
        i--;
        temp=temp->next;
    }
    temp->next=temp->next->next;
    return head;
}
