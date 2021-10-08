#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node*next;
};
int x;
struct node *top = NULL;

void push(int data)
{
    struct node *newNode;
   newNode = (struct node*)malloc(sizeof(struct node));
   newNode->data = data;
   if(top == NULL)
      newNode->next = NULL;
   else
      newNode->next = top;
   top = newNode;
}

void pop()
{
    int val;
    struct node*ptr=top;
    if(top == NULL)
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        cout<<"Element poped : "<<ptr->data<<endl;
        ptr = top->next;
        free(ptr);
    }
}

int main()
{
    int choice, y;
    while (1)
    {
        cout << "--------------Menu-----------------" << endl;
        cout << "1 push \n"
             << "2 pop \n"
             //<< "3 isEmpty \n"
            // << "4 isFull \n"
            // << "5 Print values in stack \n"
             << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element to be pushed : ";
            cin >> x;
            push(x);
            break;
        case 2:
            pop();
            //cout << "The element poped out is : " << y << endl;
            break;
        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}