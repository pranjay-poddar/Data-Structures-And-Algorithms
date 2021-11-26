//Preorder Inorder Postorder tree traversals 
#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left,*right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

void preorder(struct Node *node){
    if(node == NULL){
        return;
    }
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(struct Node *node){
    if(node == NULL){
        return;
    }
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void postorder(struct Node *node){
    if(node == NULL){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

int main()
{ 
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5); 
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

    return 0;
}
