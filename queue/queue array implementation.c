//queue array implementation
#include <stdio.h>
#define N 5
int q[N];
int front =-1,rear=-1;

//enqueue function-------------------------------------------------------------
void enq()
{
    int x;
    printf("Please enter a number to enqueue:");
    scanf("%d",&x);
    if(rear==N-1)
    {
        printf("Overflow\n");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        q[rear]=x;
    }
    else
    {
        rear++;
        q[rear]=x;
    }
}

//dequeue function-------------------------------------------------------------
void dq()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is Empty!\n");
    }
    else if(front == rear)
    {
        front = rear = -1;
    } 
    else
    {
        front++;
    }
    
}

//display function-------------------------------------------------------------
void display()
{
    int i;
    for(i = front ;i <rear +1;i++)
    {
        printf("%d ",q[i]);
    }
    printf("\n");
}

//peak function-------------------------------------------------------------
void peak()
{
    if(front == -1 && rear ==-1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("%d ",q[front]);
    }
    printf("\n");
}


int main()
{
   int num;
   printf("Press 1 to enqueue\nPress 2 to dequeue\nPress 3 to display\nPress 4 to display peak\nPress 0 to exit\n");
  do{
      printf("Choice:");
      scanf("%d",&num);
      switch(num)
      {
         case 1:
         enq();
         break;
         case 2:
         dq();
         break;
         case 3:
         display();
         break;
         case 4:
         peak();
         break;
         case 0:
         return 0;
         default:
         printf("Please enter valid choice\n");
      }
     } while(num);
return 0;
}
