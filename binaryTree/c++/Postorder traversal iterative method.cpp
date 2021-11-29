//Postorder traversal iterative method

#include<bits/stdc++.h>
#include <iostream>

using namespace std; 

struct Node{
    int data;
    Node * left,*right;
};

void postorder(Node * root){
    stack<Node*> s1;
    stack<Node*> s2;
    Node * node = root;
    s1.push(root);                  
    while(!s1.empty()){             
        Node* n = s1.top();         
        s1.pop();
        s2.push(n);
        if(n->left!=NULL)s1.push(n->left);
        if(n->right!=NULL)s1.push(n->right);
    }
    while(!s2.empty()){
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

Node * newnode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main(){
    struct Node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    
    postorder(root);
    return 0;
}