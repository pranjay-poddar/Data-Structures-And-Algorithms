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

//insertion functions---------------------------------------------------
void insertstart()
{
    int x;
    newnode=(struct node *)(malloc(sizeof(struct node)));
    printf("Enter number to be inserted:");
    scanf("%d",&x);
    newnode->data=x;
    newnode->next=head;
    head->prev=newnode;
    newnode->prev=NULL;
    head = newnode;

}

//----------------------------------------------------------------------
void insertend()
{
    struct node *temp1;
    int x;
    newnode=(struct node *)(malloc(sizeof(struct node)));
    printf("Enter number to be inserted:");
    scanf("%d",&x);
    newnode->next=NULL;
    newnode->data=x;
    temp1=head;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    newnode->prev=temp1;
    temp1->next=newnode;

}
//----------------------------------------------------------------------
void insertpos()
{
    struct node *temp1,*temp2;
    int x,pos,i=1,count=0;
    newnode=(struct node *)(malloc(sizeof(struct node)));
    printf("Enter number to be inserted:");
    scanf("%d",&x);
    printf("Enter the position to insert a number:");
    scanf("%d",&pos);
    newnode->data=x;

    temp1 = head;
    while(temp1!=NULL)
    {
        temp1=temp1->next;
        count++;
    }
    if(pos<1 || pos>count)
    {
        printf("Invalid position");
    }
    else if(pos == 1)
    {
        printf("choose option 4");
    }
    {
      temp1=temp2=head;
      while(i<pos-1)
      {
         temp1=temp1->next;
         temp2=temp1->next;
         i++;
      }
      newnode->next=temp1->next;
      newnode->prev=temp1;
      temp1->next=newnode;
      temp2->prev=newnode;
    }

}

//deletion functions----------------------------------------------------
void deletestart()
{
    struct node *temp2;
    temp2 = head;
    head=head->next;
    head->prev=NULL;
    free(temp2);

}
//----------------------------------------------------------------------
void deleteend()
{
    struct node *temp2,*pr;
    temp2=head;
    while(temp2->next!=NULL)
    {
        pr=temp2;
        temp2=temp2->next;
    }
    pr->next=NULL;
    free(temp2);

}
//----------------------------------------------------------------------
void deletepos()
{
    struct node *temp1,*temp2,*temp3;
    int pos,i=1;
    printf("Enter the position of number to be deleted:");
    scanf("%d",&pos);
    if(pos == 1)
    {
        printf("choose option 6");
    }
    else
    {
        temp1=head;
        while(i <pos-1)
        {
            temp2=temp1;
            temp1=temp1->next;
            temp3=temp1->next;
            i++;
        }
        temp2->next=temp1->next;
        temp3->prev=temp2;
        free(temp1);

    }
}

//main function--------------------------------------------------------
int main()
{
    int choice;
    printf("Please enter: \n1 to create list\n2 to display forward list\n3 to display reverse list\n4 to insert a number at beginning\n5 to insert a number at end\n6 to insert a number at a given position\n7 to delete a number from beginning\n8 to delete a number from end\n9 to delete a number from a given position\n0 to stop:\n");

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

        case 4:
        insertstart();
        break;

        case 5:
        insertend();
        break;

        case 6:
        insertpos();
        break;

        case 7:
        deletestart();
        break;

        case 8:
        deleteend();
        break;


        case 9:
        deletepos();
        break;

        case 0:
        printf("\nExit Successful");
        return 0;

        default:
        printf("Please enter a valid number");

        }
    }while(choice);
return 0;
}
