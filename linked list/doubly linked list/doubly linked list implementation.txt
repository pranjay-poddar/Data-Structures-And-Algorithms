//doubly linked list implementation
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
}*head = NULL,*newnode,*temp;

//display forward--------------------------------------
void displayf()
{
    struct node * temp2;
    temp2=head;
    while(temp2!=NULL)
    {
        printf("->%d",temp2->data);
        temp2=temp2->next;
    }
    printf("\n");
}

//display reverse--------------------------------------
void displayr()
{
    struct node* temp1;
    temp1=head;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    
    while(temp1!=NULL)
    {
        printf("->%d",temp1->data);
        temp1=temp1->prev;
    }
    printf("\n");
}

//linked list formation--------------------------------
void insert()
{
    int n;
    newnode=(struct node *)(malloc(sizeof(struct node)));
    printf("Enter number:");
    scanf("%d",&n);
    
    newnode->data=n;
    newnode->next=NULL;
    newnode->prev=NULL;
        if(head == NULL)
        {
            temp = head = newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
}

int main()
{
    int choice;
    printf("Please enter 1 insert number\n2 to display in forward\n3 to display reverse\n0 to stop:\n");
    
    do
    {
    printf("Choice:");
    scanf("%d",&choice);
       switch(choice)
       {
        case 1:
        insert();
        break;
           
        case 2:
        displayf();
        break;
           
        case 3:
        displayr();
        break;
        
            
        }
    }while(choice);
return 0;
}