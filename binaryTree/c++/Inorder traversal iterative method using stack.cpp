// Inorder traversal iterative method using stack
#include<bits/stdc++.h>
#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left,*right;
};


void inorder(Node * root){
stack<Node *> s;
Node * node = root;
while(true){
    if(node!=NULL){
      s.push(node);
      node=node->left;
    }
    else{
      if(s.empty()==true)break;
      node = s.top();
      s.pop();
      cout << node->data << " ";
      node = node->right;
    
    }
    
    
    
}
}
Node* newNode(int data){
    Node*temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    inorder(root);
    return 0;
}
