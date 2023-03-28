#include<stdio.h>
#include<stdlib.h>

struct node 
{
  int id;
  char name[20];
  int salary;
  char pn[10];
  struct node *prev,*next;
};
struct node *head=NULL;

struct node* create()
{
  struct node *new;
  new=(struct node*)malloc(sizeof(struct node));
  printf("Enter id : ");
  scanf("%d",&new->id);
  printf("Enter name : ");
  scanf("%s",new->name);
  printf("Enter your salary : ");
  scanf("%d",&new->salary);
  printf("Enter your phone number : ");
  scanf("%s",new->pn);
  new->prev=NULL;
  new->next=NULL;
  return new;
}

void insert()
{
    int x,i,j;
  struct node *temp,*new,*a,*b;
  
  if(head==NULL)
  {
     new=create();
     head=new;  
  }
  else 
  {
    printf("\nWould you like to insert :\n1.At Start\n2.At end\n3.At any position\n");
    printf("Enter your choice : ");
    scanf("%d",&x);
    
    switch (x)
    {
      case 1:
      new=create();
      new->next=head;
      head->prev=new;
      head=new;
      break;
    
     case 2:
     new=create();
     temp=head;
     while(temp->next!=NULL)
     temp=temp->next;
     temp->next=new;
     new->prev=temp;
     break;
     
     case 3:
      printf("Enter the position : ");
      scanf("%d",&i);
      new=create();
      
      temp=head;

      for(j=1;j<(i-1);j++)
      temp=temp->next;
      
      a=temp;
      b=temp->next;
      a->next=new;
      new->prev=a;
      new->next=b;
      b->prev=new;
      break;

     default:
     printf("Wrong Choice\n");
     break;
    }

  }

}

void delete()
{
   int x,i;
   struct node *temp,*a,*b;
  
 printf("\nWould you like to delete :\n1.At Start\n2.At end\n3.At any position\n");
    printf("Enter your choice : ");
    scanf("%d",&x);
    
    switch (x)
    {
      case 1:
      
      temp=head;
      head=head->next;
      head->prev=NULL;
      free(temp);
      temp=NULL;
      break;
    
     case 2:
     temp=head;
     while(temp->next!=NULL)
     temp=temp->next;

     a=temp->prev;
     a->next=NULL;
     free(temp);
     temp=NULL;
     break;
     
     case 3:
      printf("Enter the position you want to delete : ");
      scanf("%d",&i);
      
      temp=head;

      for(int j=1;j<i;j++)
      temp=temp->next;
      
      a=temp->prev;
      b=temp->next;
      a->next=b;
      b->prev=a;
      free(temp);
      temp=NULL;
      break;

     default:
     printf("Wrong Choice\n");
     break;
    }



}

void modify()
{
   int x,i=0,c;
   struct node *temp,*a,*b;
  
    printf("Enter the id you'd like to modify the data of : ");
    scanf("%d",&x);

    temp=head;
    while(temp!=NULL)
    {
        if(temp->id==x)
        {
            i=2;
            break;
        }

       temp=temp->next;
       
    }
    if(i==2)
    {
      printf("What would u like to modify?\n1.Name\n2.Salary\n3.Phone number");
      printf("\nEnter your choice : ");
      scanf("%d",&c);

      switch(c)
      {
        case 1:
        printf("Enter the new name : ");
        scanf("%s",temp->name);
        break;

        case 2:
        printf("Enter the new salary : ");
        scanf("%d",&temp->salary);
        break;

        case 3:
        printf("Enter the new phone number : ");
        scanf("%s",temp->pn);
        break; 

      }
      printf("\nModified.");
    }
    else
    printf("Error. Id not found.");
}

void display()
{
  struct node *temp;
  temp=head;
  while(temp!=NULL)
  {
    printf("Id : %d \t",temp->id);
    printf("\tName : %s \t",temp->name);
    printf("\tSalary : %d \t",temp->salary);
    printf("\tPhone Number : %s \n",temp->pn);

    temp=temp->next;
  }

}
void reverse()
{
  struct node *temp;
   temp=head;

  while(temp->next!=NULL)
    temp=temp->next;
  
  while(temp!=NULL)
  {
    printf("Id : %d \t",temp->id);
    printf("Name : %s \t",temp->name);
    printf("Salary : %d \t",temp->salary);
    printf("Phone Number : %s \n",temp->pn);

    temp=temp->prev;
  }
}

int main()
{ 
    int y;
    printf("***************DATABASE MANAGEMENT***************");
    do
    {
       printf("\nChoose an operation :\n1.Insert\n2.Delete\n3.Modify\n4.Display\n5.Reverse Display\n6.Quit\n");
       printf("Enter you choice : ");
       scanf("%d",&y);

       switch (y)
       {
       case 1:
       insert();
       break;

       case 2:
       delete();
       break;
       
       case 3:
       modify();
       break;

       case 4:
       display();
       break;
       
       case 5:
       reverse();
       break;

       case 6:
       break;

       default:
       printf("Wrong Choice");
       break;
       }

    } while (y!=6);
    
}