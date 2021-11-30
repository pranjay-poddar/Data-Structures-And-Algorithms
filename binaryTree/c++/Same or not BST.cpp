#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node * left ,*right;
};

bool same(Node *p,Node *q){
    if(p == NULL || q == NULL)
    return (p == q); 
    return (p->data == q->data)&&same(p->left,q->left)&&same(p->right,q->right); 
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
    Node * root2 = newnode(1);
    root2->left = newnode(2);
    root2->right = newnode(3);
    root2->left->right = newnode(5);
    root2->left->left = newnode(4);
    root2->left->left->left = newnode(7);
    root2->left->left->right = newnode(7);
    if(same(root,root2)){
        cout << "Same" << endl;
    }
    else{
        cout << "Not Same" << endl;
    }
    

    return 0;
}

