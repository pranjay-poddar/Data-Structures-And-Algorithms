//NAME - PRANJAY PODDAR
//REG NO. - RA1911028010129
//SECTION - J1 CSE-CC
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}   *head=NULL,*head1=NULL,*head2=NULL;//head for insertion,deletion and display of linked list
                                       //head1 and head2 for merging 2 unsorted linked lists

// insertion functions start-------------------------------------------------------------------------
void insert_at_beginning(int n)
{
    struct node *newdata;
    newdata= (struct node *)(malloc(sizeof(struct node)));
    newdata->data= n;
    newdata->next= head;
    head = newdata;
}

void insert_at_end(int n)
{
   struct node* newdata,*temp;
   newdata= (struct node *)(malloc(sizeof(struct node)));
   newdata->data=n;
   newdata->next=NULL;
   temp = head;
   while(temp->next != NULL)
    {
      temp = temp->next;
    }
   temp->next = newdata;
}

void insert_at_random(int n,int ipos)
{
   int i=1;
   struct node *newdata,*temp;
   newdata= (struct node*)(malloc(sizeof(struct node)));
   newdata->data=n;
   temp = head;
   while(i< ipos)
    {
       temp=temp->next;
       i++;
    }
    newdata->next=temp->next;
    temp->next=newdata;
}
// search data for insertion -----------------------------------------------------------------
void search(int data,int inum,int numofelements)
{
    int count=0,k;
    struct node* temp7 = head,*prev1,*newnode3;
    newnode3= (struct node*)(malloc(sizeof(struct node)));
    newnode3->data=inum;
    newnode3->next=NULL;
    while(temp7->next!=NULL)
    {

       if (temp7->data == data)
        {
           break;
        }
       count++;
       temp7=temp7->next;
    }
    if (count == numofelements-1)
    {
        temp7=head;
        while(temp7->next!=NULL)
        {
            temp7=temp7->next;
        }
        temp7->next=newnode3;
    }

    else
    {
        temp7 = head;
        for (k = 0;k <= count;k++)
        {
            prev1=temp7;
            temp7 = temp7->next;
        }
        newnode3->next=temp7;
        prev1->next=newnode3;
    }
}
// insertion functions end--------------------------------------------------------------------

// deletion functions start--------------------------------------------------------------------
void delete_at_beginning()
{
    struct node *temp;
    temp = head;
    head=head->next;
    free(temp);
}

void delete_at_end()
{
  struct node *temp = head,*prevnode;
  while(temp->next != NULL)
    {
      prevnode=temp;
      temp = temp->next;
    }
    prevnode->next=NULL;
    free(temp);
}

void delete_at_random(int dpos)
{
  struct node *temp = head,*prevnode;
  int i = 0;
  while(i < dpos)
    {
      prevnode=temp;
      temp= temp->next;
      i++;
    }
    prevnode->next=temp->next;
      free(temp);
}
// delete search function--------------------------------------------------------------------
void deletesearch()
{
  struct node* temp5,*dprev;
  int dData,count =0;
  printf("Please enter the number you want to delete from the list:\n");
  scanf("%d",&dData);
  temp5=head;
  while(temp5->data!=dData)
    {
       dprev=temp5;
       temp5=temp5->next;
       count =1;
    }
    if (count == 1)
    {
       dprev->next=temp5->next;
       free(temp5);
    }
    else
    {
       temp5=head;
       head=head->next;
       free(temp5);
    }
}
// deletion functions end--------------------------------------------------------------------

void display()
{
    struct node * temp;
    temp=head;
    printf("Final linked list: ");
    while(temp!=NULL)   //linked list traversal for display
    {
        printf("->%d",temp->data);
        temp=temp->next;
    }
    printf("\n");

}
//merge and functions -------------------start----------------------------------------

void merge()
{
   struct node* temp3;
   temp3 = head1;
   while(temp3->next != NULL)
    {
       temp3=temp3->next;
    }
    temp3->next = head2;


}
void sort()
{
 int swapped, i;
    struct node *ptr,*lptr = NULL;

    /* Checking for empty list */
    if (head1 == NULL)
        return;

    do
    {
        swapped = 0;
        ptr = head1;

        while (ptr->next != lptr)
        {
            if (ptr->data > ptr->next->data)
            {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    }
    while (swapped);
    struct node * temp6;
    temp6=head1;
    printf("Final Sorted and Merged linked list: ");
    while(temp6!=NULL)   //linked list traversal for display
    {
        printf("->%d",temp6->data);
        temp6=temp6->next;
    }
    printf("\n");

}
// merge and sort functions ---------------end----------------------------------------

// Main function ---------------------------------------------------------------------
int main()
{
    struct node *temp,*newdata;
    int n,t,num,i;
    printf("PRANJAY PODDAR   RA1911028010129\n");
    printf("Please enter number of elements in a linked list.\n");
    scanf("%d",&n);     // number of elements in Linked List
    if (n == 0)
        {
            printf("List is empty!\n");      //condition for empty linked list
            return 1;
        }
    else
{
    printf("Please enter elements of list:\n");
    for(i = 0;i < n;i++)
    {
        newdata=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newdata->data);
        newdata->next=NULL;
        if(head==NULL)
        {
            head = temp = newdata;
        }
        else
        {
            temp->next=newdata;
            temp=newdata;
        }
    }
        int inum,ipos,dpos,ichoice,dchoice;     // ipos and dpos are the positions of number to be inserted and deleted respectively
        printf("Please enter a number to be inserted.\n");
        scanf("%d",&inum);     // number to be inserted
        printf("Press 1 to insert after specified data in the list or Press 2 to insert after specified position:\n ");
        scanf("%d",&ichoice);
        if (ichoice == 1)
            {
               int data;
               printf("Please enter data after which you want to insert element:\n");
               scanf("%d",&data);
               search(data,inum,n);
            }
        else if (ichoice == 2)
        {
        printf("Please enter position of the number to be inserted.\n");
        scanf("%d",&ipos);      // position of insertion


//insert operations----------------start-----------------------------------------------
        if(ipos == 0)
           {
             insert_at_beginning(inum);
           }
        else if (ipos == n )
           {
             insert_at_end(inum);
           }
        else if(ipos > 0 && ipos < n)
           {
             insert_at_random(inum,ipos);
           }
        else
           {
             printf("Please enter a valid number.");        // condition check for valid position
             return 1;
           }
        }
        else
            {
              printf("Invalid Input\n");
              return 1;
            }
        display (head);
//insert operations-----------------end-----------------------------------------------
        printf("Press 1 to delete specific element or Press 2 to delete element from specific position: \n");
        scanf("%d",&dchoice);
        if (dchoice == 1)
            {
               deletesearch();
            }
        else if(dchoice == 2)
        {
        printf("Please enter position of the number to be deleted.\n");
        scanf("%d",&dpos);
//delete operations----------------start-----------------------------------------------
        if(dpos == 0)
           {
             delete_at_beginning();
           }
        else if (dpos == n+1)
           {
             delete_at_end();
           }
        else if(dpos > 0 && dpos < n+1)
           {
             delete_at_random(dpos);
           }
        else
           {
             printf("Please enter a valid number.");     // condition check for valid position
             return 1;
           }
        }
        else
            {
              printf("Invalid input");
              return 1;
            }
//delete operations-----------------end------------------------------------------------
       display ();   // display
   }
//merge linked list -------------------------start-------------------------------------
   struct node *temp1,*temp2,*newnode1,*newnode2;
   int num1,num2,j;
   printf("--------------------------------------------------------------\n");
   printf("For Merging and Sorting 2 linked list:\n");
   // first linked list implementation-------------------------
   printf("Please enter number of elements in first list: \n");
   scanf("%d",&num1);
   printf("Please enter elements of list:\n");
   for (i = 0;i < num1;i++)
    {
        newnode1=(struct node *)(malloc(sizeof(struct node)));
        scanf("%d",&newnode1->data);
        newnode1->next=NULL;
        if(head1==NULL){
            head1 = temp1 = newnode1;
        }
        else
        {
            temp1->next=newnode1;
            temp1 = newnode1;
        }
    }
    // Second linked list implementation-------------------------
    printf("Please enter number of elements in second list: \n");
    scanf("%d",&num2);
    printf("Please enter elements of list:\n");
    for (j = 0;j < num2;j++)
    {
        newnode2=(struct node *)(malloc(sizeof(struct node)));
        scanf("%d",&newnode2->data);
        newnode2->next=NULL;
        if(head2==NULL)
        {
            head2 = temp2 = newnode2;
        }
        else
        {
            temp2->next=newnode2;
            temp2 = newnode2;
        }
    }
   merge();
   sort();
// merge linked list -------------------------end---------------------------------------
    return 0;
}
