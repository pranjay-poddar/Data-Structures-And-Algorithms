#include <stdio.h>
struct node
{
  int data;
  struct node *left,*right;
};
struct node *root,*current,*follow,*pnode,*old;
void insert()
{
  pnode=(struct node *)malloc(sizeof(struct node));
  if (pnode==NULL)
    printf("insufficient memory");
  else
  {
    printf("Enter data to be inserted:");
    scanf("%d",&pnode->data);
    pnode->left=NULL;
    pnode->right=NULL;
    if (root==NULL)
      root=pnode;
    else
    {
      current=root;
      follow=NULL;
      while(current!=NULL)
      {
        follow=current;
        if(pnode->data < current->data)
          current=current->left;
        else
          current=current->right;
      }
      if (pnode->data < follow->data)
       follow->left=pnode;
      else
       follow->right=pnode;
    }
  }
}
void inorder(struct node * p)
{
  if(p!=NULL)
    {
      inorder(p->left);
      printf("%d ",p->data);
      inorder(p->right);
    }
}
void preorder(struct node * p)
{
  if(p!=NULL)
    { 
      printf("%d ",p->data);
      preorder(p->left);
      preorder(p->right);
    }
}
void postorder(struct node * p)
{
  if(p!=NULL)
    { 
      postorder(p->left);
      postorder(p->right);
      printf("%d ",p->data);
    }
}
void deletion()
{
  int x;
  if(root==NULL)
     printf("tree is not created\n");
  else
  {
     printf("enter data to be deleted:");
     scanf("%d",&x);
     current=root;
     follow=NULL;
     while(current->data!=x && current!=NULL)
     {
       follow=current;
       if(x<current->data)
         current=current->left;
       else
         current=current->right;
       if(current==NULL)
       break;
     }
     if(current==NULL)
        printf("%d is not found",x);
     else
     {
       //case1
       if (current->left!=NULL && current->right==NULL)
       {
         //case a
         if(current==root)
           root=root->left;
         else
           if(current==follow->left)//case b
             follow->left=current->left;
           else//case c
             follow->right=current->left;
       }
       //case2
       if (current->left==NULL && current->right!=NULL)
       {
         //case a
         if(current==root)
           root=root->right;
         else
           if(current==follow->left)//case b
             follow->left=current->right;
           else//case c
             follow->right=current->right;
       }
        //case3
       if (current->left==NULL && current->right==NULL)
       {
         //case a
         if(current==root)
           root=NULL;
         else
           if(current==follow->left)//case b
             follow->left=NULL;
           else//case c
             follow->right=NULL;
       }
        //case4
       if (current->left!=NULL && current->right!=NULL)
       {
         old=current->right;
         while(old->left!=NULL)
         {
           old=old->left;
           if(old->left==NULL)
           break;
         }
         old->left=current->left;
         //case a
         if(current==root)
           root=root->right;
         else
           if(current==follow->left)//case b
             follow->left=current->right;
           else//case c
             follow->right=current->right;
       }
       free(current);
       printf("%d is deleted",x);
    }
  }
}
void search()
{ int x;
  if(root==NULL)
     printf("tree is not created\n");
  else
  {
     printf("enter data to be search:");
     scanf("%d",&x);
     current=root;
     while(current->data!=x && current!=NULL)
     {
       if(x<current->data)
         current=current->left;
       else
         current=current->right;
       if(current==NULL)
       break;
     }
     if(current==NULL)
       printf("%d is not found\n",x);
     else
       printf("%d is found\n",x);
   }
  
}
int main()
{ 
  int ch;
  do
  {
  printf("\nEnter your choice:\n1.insert\n2.inorder\n3.preorder\n4.postorder\n5.deletion\n6.search\n7.exit\n");
  scanf("%d",&ch);
  switch (ch)
   {
    case 1: insert();
            break;
    case 2: if(root==NULL)
              printf("tree not created:\n");
            else{
             printf("Elements in the tree inorder:\n");
             inorder(root);
            }
            break;
    case 3: if(root==NULL)
              printf("tree not created:\n");
            else{
             printf("Elements in the tree preorder:\n");
             preorder(root);
            }
            break;
    case 4: if(root==NULL)
              printf("tree not created:\n");
            else{
             printf("Elements in the tree postorder:\n");
             postorder(root);
            }
            break;
    case 5: deletion();
            break;
    case 6: search();
            break;
    case 7: exit(0);
   }
  }while(ch!=7);
  return 0;
}
