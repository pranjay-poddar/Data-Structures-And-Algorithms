//Reverse a linked list 
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node* next;
}*head=NULL,*prev,*temp,*nextnode;
void display();

//reverse function------------------------------------------------------
void reverse()
{
    prev=NULL;
    temp=nextnode=head;
    while(nextnode != NULL)
    {
    nextnode= nextnode->next;
    temp->next=prev;
    prev=temp;
    temp=nextnode;
    }
    display();
}

//display function------------------------------------------------------
void display()
{
    temp= prev;
    printf("reversed Linked List:");
    while(temp!=NULL)
    {
        printf("->%d",temp->data);
        temp=temp->next;
    }
}

//main function------------------------------------------------------
int main()
{
    int i,n;
    struct node *newnode;
    printf("Number of elements in Linked List:");
    scanf("%d",&n);
    for(i = 0;i < n;i++)
    {
    newnode=(struct node *)(malloc(sizeof(struct node)));
    printf("Enter element number %d:",i+1);
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp=temp->next;
    }
    }
    //display of normal linked list
    temp=head;
    while (temp!=NULL)
    {
        printf("->%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
    reverse();
    
    return 0;
}

