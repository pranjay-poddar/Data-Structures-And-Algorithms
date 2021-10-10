#include<iostream>
#include<vector>
using namespace std;
//template for node 
struct node{
    int data;
    node* right;
    node* left;
    node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};
//n1 and n2 are the given node->data 
node* LCA(node* root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }
  //root with any of the given data is found
    if(root->data==n1 || root->data==n2){
        return root;
    }
  //search in left and right subtree for the given nodes
    node* leftlca=LCA2(root->left,n1,n2);
    node* rightlca=LCA2(root->right,n1,n2);
  
  //if one node is present in left subtree and other in right subtree then this will be the least common ancestor of the given nodes
    if(leftlca && rightlca){
        return root;
    }
    if(leftlca!=NULL){
        return leftlca;
    }
    return rightlca;
}
int main(){
  //build the tree
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->right->left=new node(4);
    root->right->left->left=new node(5);
    root->right->left->left->left=new node(7);
    root->right->right=new node(6);
    node* ans=LCA(root,6,7);
    if(ans==NULL){
        cout<<"no lca";
    }
    else{
        cout<<"lca:"<<ans->data;
    }
    return 0;
}
