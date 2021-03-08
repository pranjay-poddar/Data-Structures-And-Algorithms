#include <stdio.h>
#include <stdlib.h>
struct node
    {
        int data;
        struct node *next;
    };
int main()
{
    
    int choice=1;
    struct node *head=NULL,*temp,*newdata;
    while(choice)
    {
    
    newdata = (struct node*)(malloc(sizeof(struct node)));
    printf("Please enter  a value:\n");
    scanf("%d",&newdata->data);
    newdata->next = NULL;
    
    if (head == NULL)
    {
        head = temp = newdata;
    }
    else 
    {
        temp -> next =newdata;
        temp = newdata;
    }
    printf("please enter ur choice(0,1):");
    scanf("%d",&choice);
}
    
    temp = head;
    while (temp!= NULL)
    {
        printf("%d",temp->data);
        temp = temp->next;
    } 
    
    return 0;
}
