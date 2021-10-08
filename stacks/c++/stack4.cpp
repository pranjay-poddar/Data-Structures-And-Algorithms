#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

struct node *addEmpty(int);
struct node *add_at_end(struct node *,int);
struct node *CreateList(struct node *);
struct node *merge(struct node *,struct node *);
void printdata(struct node *);

int main()
{
    struct node *head1 = (struct node *)malloc(sizeof(struct node));
    struct node *head2 = (struct node *)malloc(sizeof(struct node));
    struct node *head3 = (struct node *)malloc(sizeof(struct node));
    head1 = CreateList(head1);
    head2 = CreateList(head2);
    head3 = merge(head1,head2);
    printdata(head3);
    return 0;
}

struct node *addEmpty(int data)
{
   struct node *NewNode = (struct node *)malloc(sizeof(struct node));
   NewNode->data = data;
   NewNode->next = NULL;
   return NewNode;
}

struct node *add_at_end(struct node *head,int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return head;
}

struct node *CreateList(struct node *head)
{
   int n,data;
   cout<<"Enter the number of nodes : ";
   cin>>n;
   cout<<"Enter the data for 1st node : ";
   cin>>data;
   head = addEmpty(data);
   for(int i =1;i<n;i++)
   {
       cout<<"Enter the data for "<<i+1<<"th node : ";
       cin>>data;
       head = add_at_end(head,data);
   }
   return head;
}

struct node *merge(struct node *head1,struct node *head2)
{
    struct node *l1 = head1;
    struct node *l2 = head2;
    struct node *res = NULL;
    if (l1 == NULL)
    {
        res = l2;
        return res;
    }
    if(l2==NULL)
    {
        res = l1;
        return res;
    }
    if(l1->data > l2->data)
    {
        swap(l1,l2);
    }
    while (l1 != NULL && l2 != NULL)
    {
        struct node *temp =NULL;
        while (l1 != NULL && l1->data <= l2->data)
        {
            temp = l1;
            l1 = l1->next;
        }
        temp = l2;
        swap(l1,l2);
    }
    res = l1;
    return res;
}

void printdata(struct node *head3)
{
    struct node *ptr = head3;
    while (ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}