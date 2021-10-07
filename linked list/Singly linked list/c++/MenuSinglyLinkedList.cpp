/*  Single Linked List */

#include <iostream>
using namespace std;
struct linklist              
                             
{                      
    int item;        
    struct linklist *next;
};
typedef struct linklist node;
node *head=NULL;
int main()                
{
    int ch;
   
    void create();
    void display();
    void insert_mid();
    void insert_beg();
    void del_beg();
    void del_end();
    void del_mid();
    void search();
  do{
      printf("\nEnter the choice ");
      cin>>ch;
     
      switch(ch)
      {
          case 1: create(); break; // head node and insert at the end of the list
          case 2: display(); break;
          case 3: insert_beg(); break;
          case 4: insert_mid(); break;
          case 5: del_beg();break;
          case 6: del_end();break;
          case 7: del_mid(); break;
          case 8: search();break;
          case 9: break;
      }
  }while(ch!=9);
    return 0;
}
void create()                  
{
     if(head==NULL)
     {
        head = new node;  
        cout<<"Enter the element ";
        cin>>head->item;
        head->next=NULL;              
     }  
     else  //inert at the end of the list
     {
        node *p=head,*q;
        while(p->next!=NULL)
        {p=p->next;}           //take the pointer to the last node
       
        q = new node;  //create the new node
        cout<<"Enter the element ";
        cin>>q->item;
        q->next=NULL;
       
        p->next=q;
     }
                                           
}
void display()                
{
node *p=head;
if(p==NULL)
{
    cout<<"No element in the list";
    return;
}
while(p!=NULL)
{
    cout<<" "<<p->item;  
    p=p->next;  
}
}
void insert_beg()
{
    node *p;
    p=new node;
    cin>>p->item;
    p->next=head;
    head=p;
   
}
void insert_mid()                
{
     int num;
    cout<< "Enter the item after which number you want to add the new node";
    cin>>num;
    node *p=head;
    while(p->item!=num)             
    {                                            
        p=p->next;
    }
    node *q;
    q=new node;
    cin>>q->item;
    q->next=p->next; 
    p->next=q;       
   
}
void del_beg()  
{
    int ele;
    if(head==NULL){
    cout<<"No element to be deleted";
    return;
    }
    node *p=head;
    ele=p->item;
    head=p->next;
    delete(p);
    cout<<"deleted element "<<ele;
  }
void del_end()  
{
    if(head==NULL)
    {
        cout<<"No element to be deleted";
        return;
    }
   
    node *p=head;
    if(p->next==NULL)  //if there is only one node
    {
        cout<<"deleted element= "<<p->item;
        delete(p);
        head=NULL;
    }
    else
    {
    while(p->next->next!=NULL)  //if more than one nodes
    {
    p=p->next;
    }
    int ele;
    ele=p->next->item;//30
    delete(p->next);
    p->next=NULL;
    cout<<"deleted element="<<ele;
}  
 }
 void del_mid()
  {
      int num;
      if(head==NULL)
    {
        cout<<"No element to be deleted";
        return;
    }
     cout<<"Enter the middle element ";
     cin>>num;// num=30
     node *p=head, *q;
     while(p->next->item!=num)
     {
         p=p->next;
     }
     q=p->next->next;
     delete(p->next); //free the memory
     
     p->next=q;
   }
 void search()
 {
      int ele;
     node *p;
     cout<<"Enter the element";
     cin>>ele;
     for(p=head;p!=NULL; p=p->next)
     {
         if(p->item==ele)
         {
             cout<<"Found";
         return;
         }
     }
          cout<< "not found";
     
     
 }