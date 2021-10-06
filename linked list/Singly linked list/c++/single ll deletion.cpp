#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * next;
}*head,*newnode,*temp,*pre;

void printlist(){
temp = head ;
while( temp!=0){
    cout << temp->data << "->";
    temp = temp->next;
}
}
void insertb(){
    newnode = new Node();
    cout <<"Please enter a number to insert at begining: ";
    cin >> newnode->data;
    temp = head;
    newnode->next = head;
    head = newnode;
    cout << endl;
    printlist();
}
void insertm(){
    int n = 1,pos;
    cout << endl << "Please enter the position to enter the number: ";
    cin >> pos;
    newnode = new Node();
    cout <<"Please enter a number to insert in middle: ";
    cin >> newnode->data;
    temp = head;
    while( n < pos){
        temp = temp->next;
        n++;
    }
    newnode->next=temp->next;
    temp->next = newnode;
    cout<<endl;
    printlist();
    
}
void inserte(){
    newnode = new Node();
    cout << endl << "Please enter a number to insert at the end: ";
    cin >> newnode->data;
    newnode->next = 0;
    temp = head ;
    while(temp->next!=0){
      temp= temp->next;
    }
      temp->next = newnode;
    cout << endl;
    printlist();
}
int deleteb(){
    temp = head;
    if (temp != 0){
        head = temp->next;
        delete temp;
    }
    else{
        return 0;
    }
    cout << endl << "After deletion from begining\n";
    printlist();
}
int deletem(){
    temp = head;
    int pos,n=1;
    cout << " \nPlease enter the position to delete the number: ";
    cin >> pos;
    while(n < pos){
        pre = temp;
        temp=temp->next;
        n++;
    }
    pre->next=temp->next;
    delete temp;
    cout << endl << "After deletion from middle\n";
    printlist();
    
}
void deletee(){
    temp = head;
    
    while(temp->next!=0){
        pre = temp;
        temp = temp->next;
    }
    pre->next = 0;
    delete temp;
    cout << endl << "After deletion from end\n";
    printlist();
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
cout << endl;
// insertb();
// insertm();
// inserte();
deleteb();
deletem();
deletee();
    return 0;
}
