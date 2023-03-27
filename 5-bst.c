#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *left, *right;
};

struct node* create(int d)
{
  struct node *new;
  new=(struct node*)malloc(sizeof(struct node));
  new->data=d;
  new->right=NULL;
  new->left=NULL;
  return new;
}

struct node* insert(struct node* root,int d)
{
  if(root==NULL)
  return create(d);
  else
  {
   if(d<root->data)
   root->left=insert(root->left,d);
   else
   root->right=insert(root->right,d);

   return root;
  }
}

struct node* delete(struct node *root,int d)
{
  if(root==NULL)
  return root;
  else
  {
    if(d<root->data)
    root->left=delete(root->left,d);
    else if(d>root->data)
    root->right= delete(root->right,d);
    else
    {
      if(root->right==NULL)
      {
        struct node *temp;
        temp=root->left;
        free(root);
        return temp;
      }
      else
      { 
        struct node *temp;
        temp=root->right;
        root->data=inorderS(temp);
        root->right= delete(root->right,root->data);
      }
    }

   return root;
   
  }
}

int inorderS(struct node *temp)
{
  while(temp && temp->left!=NULL)
  temp=temp->left;
  return temp->data;

}

int search(struct node * root,int d)
{
   if(root==NULL)
   return 0;
   else
   {
     if(root->data==d)
     return 1;
     else if(d<root->data)
     search(root->left,d);
     else 
     search(root->right,d);
     
   }

}

void inOrder(struct node* root)
{
  if(root!=NULL)
  {
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
  }
}


int main()
{
  int y,d,s;
  struct node* root;
  root=NULL;
  printf("******************BST TREE******************");
  do
  {
    printf("\nChoose one of the operations :\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Quit\n");
    printf("Your choice : ");
    scanf("%d",&y);

    switch(y)
    {
        case 1:
        printf("\nEnter data : ");
        scanf("%d",&d);
        root=insert(root,d);
        break;

        case 2:
        printf("Enter the element you'd like to delete : ");
        scanf("%d",&d);
        delete(root,d);
       // if(s==0)
        //printf("Element not found\n");
       // else
       // printf("Element has been deleted.\n");
        break;

        case 3:
        printf("\nEnter the data you'd like to search for : ");
        scanf("%d",&d);
        s=search(root,d);
        if(s==1)
        printf("Element is found !!\n");
        else
        printf("Element is NOT found !!\n");
        break;

        case 4:
        inOrder(root);
        break;

        case 5:
        break;

        default:
        printf("\nWrong choice\n");
    }  


  } while(y!=5);
  

}
