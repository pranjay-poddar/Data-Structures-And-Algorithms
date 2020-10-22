//stack operations using linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node * next;
}*top =NULL;

//push function-----------------------------------------------------
void push()
{
    int n;
    printf("Enter element:");
    scanf("%d",&n);
    struct node* newnode;
    newnode = (struct node *)(malloc(sizeof(struct node)));
    newnode->data=n;
    newnode->next=top;
    top=newnode;
}

//pop function-----------------------------------------------------
void pop()
{
    struct node *temp=top;
    if(temp==NULL)
    {
        printf("Underflow\n");
    }
    else
    {
    
    printf("The popped element is:%d \n",top->data);
    top=top->next;
    free(temp);
    }
}

//display function-----------------------------------------------------
void display()
{
    struct node *temp;
    temp = top;
    while(temp!=0)
    {
        printf("->%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

//main function-----------------------------------------------------
int main()
{
    int i,choice;
    printf("Press 1 to push element.\nPress 2 to pop element\nPress 3 to display list\nPress 0 to exit\n");
    
    do 
    {
     printf("Choice:");
     scanf("%d",&choice);
     switch(choice)
     {
         case 1:
         push();
         break;
         
         case 2:
         pop();
         break;
         
         case 3:
         display();
         break;
         
         case 0:
         return 0;
         
         default:
         printf("Enter a valid number\n");
     }   
    }while(choice);
    return 0;
}