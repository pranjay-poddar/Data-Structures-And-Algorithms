#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node * left ,*right;
};

Node * newnode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


vector<vector<int>>zigzag(Node * root){
vector<vector<int>> ans;
bool flag = true;
if(root == NULL)return ans;
queue<Node *> q;
q.push(root);
while(!q.empty()){
    
    int size = q.size();
    vector<int> row(size);
    for(int i = 0; i < size;i++){
        Node * node = q.front();
        q.pop();
        int index = (flag) ? i : (size - 1 - i);
        row[index]= node->data;
        if(node->left!=NULL)q.push(node->left);
        if(node->right!=NULL)q.push(node->right);
    }
    flag = !flag;
    ans.push_back(row);
    
}
return ans;
} 

int main()
{
    Node * root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->right = newnode(5);
    root->left->left = newnode(4);
    root->left->left->left = newnode(7);
    vector<vector<int>> v = zigzag(root);
    for(int i = 0;i < v.size();i++){
        for(int j = 0;j < v[i].size();j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}

