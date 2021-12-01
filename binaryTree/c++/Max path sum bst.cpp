#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node * left ,*right;
};

int sum = INT_MIN;

Node * newnode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


int maxpath(Node *root){
    if(root == NULL)return 0;
    int lsum = max(0,maxpath(root->left));
    int rsum = max(0,maxpath(root->right));
    sum = max(sum,(root->data + rsum+lsum));
    return root->data + max(rsum,lsum);
}

int main()
{
    Node * root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->right = newnode(5);
    root->left->left = newnode(4);
    root->left->left->left = newnode(7);
    maxpath(root);
    cout << sum;
    

    return 0;
}

