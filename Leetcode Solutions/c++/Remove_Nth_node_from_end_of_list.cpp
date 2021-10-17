/*
SUBMITTED BY: Deadeye001
DATE: 17/10/21
*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first=head;
        ListNode* second=head;
        if(second->next==NULL)
            return NULL;
        for(int i=0;i<n;i++)
            second=second->next;
        if(second==NULL)
        {
            head=head->next;
            return head;
        }
        while(second->next)
        {
            second=second->next;
            first=first->next;
        }
        ListNode* temp=first->next;
        first->next=first->next->next;
        delete temp;
        return head;
    }
};
