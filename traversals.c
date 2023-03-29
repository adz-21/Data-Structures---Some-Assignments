#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node 
{
  int data;
  struct node *right; 
  struct node *left ;
};

struct node* createNode(int);
void postOrder(struct node*);
void preOrder(struct node *);
void inOrder(struct node *);

int main()
{
   struct node *root, *a,*b,*a1,*a2;  
   root=createNode(4);
   a=createNode(1);
   b=createNode(6);
   a1=createNode(5); 
   a2=createNode(2);

   // The tree below is made :  
  /*
             4
           /  \
          1    6 
         /  \
        5    2 
  */
  root->left=a;
  root->right=b;
  a->left=a1;
  a->right=a2;
 
  printf("Preorder : ");
  preOrder(root);
  printf("\nPostorder : ");
  postOrder(root);
  printf("\nInorder : ");
  inOrder(root);
 return 0;
}

struct node* createNode(int d)
{
  struct node* new;
  new = (struct node*)malloc(sizeof(struct node));
  new->data=d;
  new->right=NULL;
  new->left=NULL;
  return new;
}

void preOrder(struct node* root)
{
  if(root!=NULL)
  {
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);

  }
}

void postOrder(struct node *root)
{
  if(root!=NULL)
  {
  postOrder(root->left);
  postOrder(root->right);
  printf("%d ",root->data);
  }
}

void inOrder(struct node *root)
{
  if(root!=NULL)
  {
  inOrder(root->left);
  printf("%d ",root->data);
  inOrder(root->right);
  }
}
