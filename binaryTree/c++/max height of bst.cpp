// max depth / max Height

#include<bits/stdc++.h>
#include <iostream>

using namespace std; 

struct Node{
    int data;
    Node * left,*right;
};

int maxdepth(Node * root){
    if(root == NULL)return -1;
    else{
    int ld= maxdepth(root->left);
    int rd= maxdepth(root->right);
    
    if(ld > rd){
        return ld + 1;
    }
    else{
        return rd + 1;
    }
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
    
    cout << "Height of the tree is: "<< maxdepth(root);
    return 0;
}