#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node * left ,*right;
};

int dfsheight(Node *);

bool balanced(Node * root){
    if(root == NULL)return true;
    return dfsheight(root) != -1;
}

int dfsheight(Node * root){
    if(root == NULL)return 0;
    int lh = dfsheight(root->left);
    if(lh == -1)return -1;
    int rh = dfsheight(root->right);
    if(rh == -1)return -1;
    if(abs(lh-rh) > 1) return -1;
    
    return 1 + max(lh,rh);
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
    if(balanced(root)){
        cout << "Balanced" << endl;
    }
    else{
        cout << "Not balanced" << endl;
    }
    

    return 0;
}

