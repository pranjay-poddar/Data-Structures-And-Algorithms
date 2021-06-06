#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * next;
}*head,*newnode,*temp,*temp1;

void printlist(){
temp = head ;
while( temp!=0){
    cout << temp->data << "->";
    temp = temp->next;
}
}

int main()
{
    int num;
    cout << "Please enter the number of elements: ";
    cin >> num;
    head = 0;
    while(num--){
    newnode = new Node();
    cout << "Please enter the number: ";
    cin >> newnode->data;
    newnode->next=0;
    if (head == 0){
        temp = head = newnode;
    }
    else{
        temp->next = newnode;
        temp = newnode;
    }
    }
printlist();
    return 0;
}
