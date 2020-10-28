//circular queue linked list implementation
#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* next;
}*front = NULL,*rear=NULL;

//enqueue function--------------------------------------------------------
void enq()
{
    int num;
    struct node* newnode;
    newnode=(struct node*)(malloc(sizeof(struct node)));
    printf("Please enter number to enqueue:");
    scanf("%d",&num);
    newnode->data=num;
    newnode->next=NULL;
    if(rear == NULL)
    {
        front = rear = newnode;
        rear->next=front;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}

//dequeue function--------------------------------------------------------
void dq()
{
    struct node *temp=front;
    if(front == NULL && rear == NULL)
    {
        printf("Queue is empty!\n");
    }
    else if(front == rear)
    {
        front=rear=NULL;
        free(temp);
    }
    else
    {
        front=front->next;
        rear->next =front;
        free(temp);
    }
}

//peak function--------------------------------------------------------
void peak()
{
    struct node *temp=front;
    if(front == NULL && rear ==NULL)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("%d\n",temp->data);
    }
}

//display function--------------------------------------------------------
void display()
{
    struct node * temp=front;
    if(front == NULL && rear == NULL)
    {
        printf("Queue is empty!\n");
    }
    else
    {
      while(temp->next != front)
      {
         printf("%d ",temp->data);
         temp=temp->next;
      }
      printf("%d",temp->data);
      printf("\n");
    }
}

//main function--------------------------------------------------------
int main()
{
   int choice;
   printf("Press 1 to enqueue\nPress 2 to dequeue\nPress 3 to display peak\nPress 4 to display queue\nPress 0 to exit\n");
   do
   {
       printf("Choice:");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
           enq();
           break;
           case 2:
           dq();
           break;
           case 3:
           peak();
           break;
           case 4:
           display();
           break;
           case 0:
           return 0;
           default:
           printf("Please input valid choice\n");
       }
       
   }while(choice);
    return 0;
}
