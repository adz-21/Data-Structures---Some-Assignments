#A simple approach to store the members of a Pinnacle Club + perform operations - add/delete member, display list in order + in reverse

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
  char name[20];
  int PRN;
  struct node *next, *prev;

} *head,*last,*temp;

void presNode()
 { 
    head=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the President's name : ");
    scanf("%s",head->name);
    printf("Enter PRN : ");
    scanf("%d",&head->PRN);
    head->prev=NULL;
    head->next=NULL;
    temp=head;
 }
 
 void lastNode()
 {
   last=(struct node*)malloc(sizeof(struct node));
   printf("\nEnter the Secretary's name : ");
   scanf("%s",last->name);
   printf("Enter PRN : ");
   scanf("%d",&last->PRN);
   last->prev=head;
   last->next=NULL;
   head->next=last;
 }

 void addMember()
 {

   struct node *new;
   new=(struct node*)malloc(sizeof(struct node));
   printf("Enter the member's name : ");
   scanf("%s",new->name);
   printf("Enter PRN : ");
   scanf("%d",&new->PRN);
   new->prev=NULL;
   new->next=NULL;
    
   temp->next=new;
   new->prev=temp;
   new->next=last;
   last->prev=new; 
   temp=new;

 }

 void count()
 { 
   int n=0;
   struct node *temp2;
   temp2=head;
   while(temp2!=NULL)
   {
    n++;
    temp2=temp2->next;
   }
   printf("Total number of members : %d \n",n);

 }

 void display()
 {
   struct node* current;
   current=head;
   printf("List : \n");
   while(current!=NULL)
   {
     printf("Member name : %s\t",current->name);
     printf("PRN : %d\n",current->PRN);
     current= current->next;
   }
}

void displayRev()
{
  struct node *current;
  current=last;
  printf("Reversed List : \n");
  while(current!=NULL)
  {
   printf("Member name : %s\t",current->name);
   printf("PRN : %d\n",current->PRN);
   current= current->prev;
  }
}  

deleteMember()
{
  int y,p,x=1;
  struct node *current,*a,*b;
  printf("\nWould you like to delete :\n1.The president\n2.The secretary\n3.Other members\n");
  printf("Enter your choice : ");
  scanf("%d",&y);
  
  switch(y)
  {
    case 1:
    temp=head;
    //free(head);
    head=temp->next;
    head->prev=NULL;
    free(temp);
    printf("The president has been deleted.\n");
    break;

    case 2:
    temp=last;
    //free(last);
    last=temp->prev;
    last->next=NULL;
    free(temp);
    printf("The secretary has been deleted.\n");
    break;

    case 3:
    printf("Enter the PRN of the member you'd like to delete : ");
    scanf("%d",&p);
    temp=head;
    while(temp!=NULL)
    { 
      if(temp->PRN==p) 
      {
        current=temp;
        x=2;
      }
      temp=temp->next;
    }

    if(x==2)
    {
      a=current->prev;
      b=current->next;
      temp=current;
      a->next=b;
      free(temp);
      temp=NULL;
      
      printf("Member deleted.\n");
    }
    else
    printf("Member not found.\n");

    break;

    default:
    printf("Wrong Choice\n");

  }
}

 int main()
 {
 
  int y;
  printf("\n\n***********************PINNACLE CLUB***********************\n\n");

  presNode();
  lastNode();
  
  do
  {
    printf("\n\t Choose any operation :\n1.Add a member\n2.Delete a member\n3.Count the members\n4.Display the list\n5.Display the list in reverse\n6.Quit\n");
    printf("\nYour choice : ");
    scanf("%d",&y);

    switch(y)
    {
      case 1:
      addMember();
      break;

      case 2:
      deleteMember();
      break;

      case 3:
      count();
      break;

      case 4:
      display();
      break;

      case 5:
      displayRev();
      break;

      case 6:
      break;

      default:
      printf("\nInvalid Choice\n");

    }

  } while (y!=6);
  
 }
