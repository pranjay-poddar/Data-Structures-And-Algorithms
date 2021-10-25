/*First make a dummy node assign its value to 0 and its next point to the head of the orignal linked list.
make a pointer of type ListNode for traversing the dummy linked list and point it to the head of dummy linked list.
then traverse the dummy list upto the left position given in the question.
then define a current pointer (as the working pointer) and point it to the next of your prev pointed node.
then define a nextnode pointer (work as the node to be extracted) and point ite to the niext of current pointed node.
now now now understand the intusion.
while(left<right){
you have to make a link between the next of the current node and the next of the nextnode node
then you have to make a link between next of the nextnode and the next of the prev node.
then lastly develop the link between the next of prev node and the nextnode

left++;
}
*/



ListNode* reverseBetween(ListNode* head, int left, int right) {

   if(head==NULL || left==right) return head;
           
       ListNode *dummy=new ListNode(0,head);
        ListNode *prev=dummy;
        int pos=1;
        while(pos<left) prev=prev->next ,  pos++;
                
               
        ListNode *current=prev->next;
        
        while(left<right){
                ListNode *nextnode=current->next;
                current->next=nextnode->next;
                nextnode->next=prev->next;
                prev->next=nextnode;
                left++;
        }
        return dummy->next;
    
}