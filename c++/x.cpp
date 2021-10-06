#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
}*head,*newnode,*temp;

void insert(int n){
    
        newnode = new Node();
        newnode->next = 0;
        newnode->data = n;
    if(head ==0){
        temp = head =newnode;
    }
    else{
        temp->next = newnode;
        temp=newnode;
    }
}

void printl(){
    temp = head ;
    while(temp!=0){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main() {
int n;
    head = 0;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        insert(num);
    }
    printl();
    return 0;
}
