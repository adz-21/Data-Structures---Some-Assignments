//Searching for an element - in a specified tree 

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *right, *left;

};

struct node * createNode(int d)
{
 struct node * new;
 new= malloc(sizeof(struct node));
 new->data=d;
 new->right=NULL;
 new->left=NULL;
}

int search (struct node* root,int d)
{
  if(root->data==d)
  return 1;
  if(root==NULL)
  return 0;
  else if(d<root->data)
  return(search(root->left,d));
  else
  return(search(root->right,d));
}

int main()
{
   int x,s;
   struct node *root,*a,*b,*a1,*a2;
   
   //Create a tree 
   root=createNode(5);
   a=createNode(3);
   b=createNode(6);
   a1=createNode(1);
   a2=createNode(2);

   root->left=a;
   root->right=b;
   a->left=a1;
   a->right=a2;
  
  /*  Tree : 
   
        5
       / \
      3   6
     / \
    1   2

  */

 printf("Enter the number to be searched : ");
 scanf("%d",&x);
 s=search(root,x);
 if(s==0)
 printf("\nNOT FOUND\n");
 else
 printf("\nFOUND\n");
}

