#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node * left ,*right;
};

int maximum = 0;

int diameter(Node * root){
    if(root == NULL)return 0;
    
    int lh = diameter(root->left);
    int rh = diameter(root->right);
    maximum = max(maximum,lh+rh);
    return max(lh,rh)+1;
    
}

Node * newnode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


int main()
{
    Node * root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->right = newnode(5);
    root->left->left = newnode(4);
    root->left->left->left = newnode(7);
    diameter(root);
    cout << maximum;
    return 0;
}


