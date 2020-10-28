//circular queue array implementation
#include <stdio.h>
#define N 5
int q[N];
int front=-1,rear=-1;

//enqueue function--------------------------------------------------------
void enq()
{
    int num;
    printf("Please enter number to enqueue:");
    scanf("%d",&num);
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        q[rear]=num;
    }
    else if((rear + 1)%N == front)
    {
        printf("Queue is full\n");
    }
    else
    {
        rear = (rear + 1)%N;
        q[rear]= num;
    }
}

//dequeue function--------------------------------------------------------
void dq()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty!\n");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front=(front+1)%N;
    }
}

//peak function--------------------------------------------------------
void peak()
{
    if(front == -1 && rear ==-1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("%d\n",q[front]);
    }
}

//display function--------------------------------------------------------
void display()
{
    int i = front;
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
      while(i!=rear)
      {
         printf("%d ",q[i]);
         i = (i+1) % N;
      }
      printf("%d",q[rear]);
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
