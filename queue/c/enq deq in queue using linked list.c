#include <stdio.h>
#include <stdlib.h>
#define N 5
int num;
//function prototypes
void enq();
void deq();

struct node
{
  int data;
  struct node* next;
}*front=NULL,*rear=NULL,*newnode;

//enqueue function
void enq()
{
  newnode=(struct node *)(malloc)(sizeof(struct node));
  
  int x;
  scanf("%d",&x);
  newnode->data=x;
  newnode->next=NULL;
   if(front == 0 && rear == 0)
   {
     front=rear=newnode;
   }
  else
  {
    rear->next=newnode;
    rear=newnode;
  }
}

//dequeue function
void deq()
{
  if(front == rear)
  {
    printf("Underflow");
    num=0;
    
  }
  else
  {
     struct node* temp =front;
     front=front->next;
     free(temp);
  }
}

//display function
void display()
{
  struct node*temp=front;
  while(temp!=NULL)
  {
    printf("%d->",temp->data);
    temp=temp->next;
  }
  printf("\n");
}

//main function
int main() {
  do{
    scanf("%d",&num);
    switch(num)
    {
      case 1:
        
        enq();
        break;
      case 2:
        deq();
        break;
      case 3:
        display();
        break;
    }
    }while(num);
	return 0;
}