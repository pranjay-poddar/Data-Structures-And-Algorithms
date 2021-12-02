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

bool isleaf(Node *root){
    if(root==NULL)return false;
    else if(root->left == NULL &&root->right==NULL)return true;
    return false;
}

void addleft(Node *root,vector<int>&ans){
    Node * cur = root;
    if(!isleaf(cur))ans.push_back(cur->data);
    if(cur->left!=NULL)addleft(cur->left,ans);
    if(cur->right!=NULL)addleft(cur->right,ans);
}

void addleaves(Node *root,vector<int> &ans){
    if(isleaf(root))ans.push_back(root->data);
    if(root->left!=NULL) addleaves(root->left,ans);
    if(root->right!=NULL) addleaves(root->right,ans);
}

void addright(Node *root,vector<int> &ans){
    Node *cur = root;
    vector<int> temp;
    if(!isleaf(cur))temp.push_back(cur->data);
    if(cur->right!=NULL) addright(cur->right,ans);
    if(cur->left !=NULL) addright(cur->left,ans);
    
    for(int i = temp.size()-1;i >= 0;i--){
        ans.push_back(temp[i]);
    }
}

vector<int>boundary(Node *root){
    vector<int> ans;
    if(root == NULL) return ans;
    if(!isleaf(root))ans.push_back(root->data);
    addleft(root->left,ans);
    addleaves(root,ans);
    addright(root->right,ans);
    return ans;
}

int main()
{
    Node * root = newnode(1);
    root->left = newnode(2);
    root->left->left = newnode(3);
    root->left->left->right = newnode(4);
    root->left->left->right->left = newnode(5);
    root->left->left->right->right = newnode(6);
    root->right = newnode(7);
    root->right->right = newnode(8);
    root->right->right->left = newnode(9);
    root->right->right->left->left = newnode(10);
    root->right->right->left->right = newnode(11);
    vector<int> v = boundary(root);
    for(int i = 0;i < v.size();i++){
        cout << v[i] << " ";
    }
    return 0;
}


