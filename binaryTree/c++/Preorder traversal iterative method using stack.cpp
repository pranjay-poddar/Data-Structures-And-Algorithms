// Preorder traversal iterative method using stack
#include<bits/stdc++.h>
#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left,*right;
};


void preorder(Node * root){
stack<Node *> s;
s.push(root);
while(!s.empty()){
    Node *node = s.top();
    s.pop();
    cout << node->data << " ";
    if(node->right != NULL)s.push(node->right);
    if(node->left != NULL)s.push(node->left);
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
    preorder(root);
    return 0;
}
