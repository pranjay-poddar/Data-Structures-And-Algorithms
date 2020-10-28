#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node*next;
} *front = NULL,*rear=NULL;

//enqueue function----------------------------------------------------------------
void enq()
{
    struct node* newnode;
    int x;
    newnode=(struct node *)(malloc(sizeof(struct node)));
    printf("Please enter number to enqueue:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    
    if(front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

//dequeue function----------------------------------------------------------------
void dq()
{
    struct node *temp=front;
    
    if(front == NULL && rear == NULL)
    {
        printf("Queue is empty!\n");
    }
    else if(front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front=front->next;
        free(temp);
    }
}

//peak function----------------------------------------------------------------
void peak()
{
    if(front == NULL && rear == NULL)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("%d\n",front->data);
    }
    
}

//display function----------------------------------------------------------------
void display()
{
    struct node *temp=front;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

//main function----------------------------------------------------------------
int main()
{
    printf("Press 1 to enqueue\nPress 2 to dequeue\nPress 3 to display peak\nPress 4 to display\nPress 0 to exit\n");
    int num;
    do
    {
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
            peak();
            break;
            case 4:
            display();
            break;
            case 0:
            return 0;
            default:
            printf("Please enter valid Input\n");
        }
    } while(num);

    return 0;
}
