//////Reverse Linked List (#2 Linked List Recursively).java

//Recursive solution
//Time: O(n)
//Space: O(n)
class Solution {
    //Return the head of the new list
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null)
            return head;
        ListNode prevPart = reverseList(head.next);
        head.next.next = head;//head.next.next is the node before head in the new list
        head.next = null;//Now head become the last node in the list
        return prevPart;//Return the head of the new list
    }
}
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
 
 
 
/////////Reverse Linked List (#1 Linked List Iteratively).java

//Iterative solution
//Time: O(n)
//Space: O(1)
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode curr = head, prev = null, temp = null;
        while(curr != null) {
            temp = curr.next;//Store the new head of the sub-linkedlist
            curr.next = prev;//Reverse happens here
            prev = curr;     //Move curr & prev to the next place
            curr = temp;
        }
        return prev;
    }
}
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
