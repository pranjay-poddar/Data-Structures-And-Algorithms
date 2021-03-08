#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*top=NULL,*top_rev=NULL,*newnode;

//function prototypes
void display(struct node *top);
void reverse(struct node **top,struct node **top_rev);
void push(int num,struct node **top);
int pop(struct node **top);

//push function
void push(int num,struct node **top)
{
    newnode=(struct node*)malloc((sizeof(struct node)));
    newnode->data=num;
    newnode->next=(*top);
    *top=newnode;
}

//pop function
int pop(struct node **top)
{
    struct node *temp=(*top);
    int del_num=temp->data;
    *top=temp->next;
    free(temp);
    return del_num;
}

//display function
void display(struct node *top)
{
    struct node* temp = top;
    while(temp!=NULL)
    {
        if(temp->next!=NULL)
        {
            printf("%d ",temp->data);
        }
        else
        {
            printf("%d",temp->data);  
        }
        temp=temp->next;
    }
}

int main()
{
    int n,i,num;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        push(num,&top);
    }
    //original stack
    printf("Original Stack:\n");
    display(top);
    //reverse stack
    printf("\nReverse stack:\n");
    reverse(&top,&top_rev);
    display(top_rev);
    
return 0;    
}

void reverse(struct node **top,struct node **top_rev)
{
    if((*top)->next==NULL)
    {
        int delete_num2=pop(top);
        push(delete_num2,top_rev);
    }
    else
    {
        int delete_num=pop(top);
        push(delete_num,top_rev);
        reverse(top,top_rev);
    }
    
}