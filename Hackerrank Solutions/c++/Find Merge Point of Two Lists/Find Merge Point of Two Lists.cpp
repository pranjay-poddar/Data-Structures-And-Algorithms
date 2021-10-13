

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
  SinglyLinkedListNode* temp1=head1;
  SinglyLinkedListNode* temp2=head2;

  while(temp1!=temp2){
    temp1=temp1->next;
      temp2=temp2->next; 
      if(!temp1)
      temp1=head1;
      if(!temp2)
      temp2=head2;}
/*if(temp1->next==temp2->next)
  {
      
    return temp1->data;  
      
      
  }
  else
  {
      temp1=temp1->next;
      temp2=temp2->next; 
      
  }
   
  }*/
return temp1->data;


}

