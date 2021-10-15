#include<iostream>
using namespace std;

///In this we have 2 pointers next and previous at every node.

class Node
{
public:
    int Data;
    Node* next;
    Node* prev;

    Node(int Value)
    {
        Data= Value;
        next=NULL;
        prev=NULL;
    }
};

///Here we are inserting at the head of Linked List.
void InsertAtHead(Node* &head,int Value)
{
     Node* n=new Node(Value);

     n->next=head;
     if(head!=NULL)   ///its because if head  is null then we can't access its previous.
     {
        head->prev=n;
     }

     head=n;
}
///Here we are inserting at the tail of Linked List.
void InsertAtTail(Node* &head,int Value)
{
    if(head==NULL)
    {
        InsertAtHead(head,Value);
        return;
    }
    Node* n= new Node(Value);

    Node* temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;  
}
///Here we are displaying complete Linked List.
void Display(Node* head)
{
    Node* n=head;

    while(n->next!=NULL)
    {
        cout<<n->Data<<"->";
        n=n->next;
    }
    cout<<"NULL"<<endl;
}
///Here we are deleting at the head of Linked List.
void DeleteAtHead(Node* &head)
{
    Node* todelete=head;
    head=head->next;
    head->prev=NULL;

    delete todelete;
}

///Here we are deleting at particular position of Linked List.
void Deletion(Node* &head,int pos)
{
    if(pos==1)
    {
        DeleteAtHead(head);
        return;
    }
    Node* temp=head;
    int Count=1;
    while(temp!=NULL && Count!=pos)
    {
        temp=temp->next;
        Count++;
    }
    temp->prev->next=temp->next;

    if(temp->next!=NULL)   
    {
       temp->next->prev=temp->prev;
    }


    delete temp;
}


int main()
{
    Node* head=NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    Display(head);
    InsertAtHead(head,6);
    InsertAtHead(head,7);
    InsertAtHead(head,8);
    Display(head);

    Deletion(head,1);
    Display(head);
}
