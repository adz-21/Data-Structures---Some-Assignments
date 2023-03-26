#include<stdio.h>
#include<stdlib.h>
#define size 5
int q[size];
int f=-1;
int r=-1;

void enqueue()
{
  int d;
   if((r+1)%size==f)
    printf("FULL\n");
    else
    {
     printf("Enter an element :   ");
     scanf("%d",&d);
      if(f==-1 && r==-1)
      {
        f=0; r=0;
        q[r]=d;  
      }
      else
      {
       r=(r+1) %size;
       q[r]=d;

      }
    } 
}

void dequeue()
{
  if(f==-1 && r==-1)
  printf("EMPTY\n");
  else if(f==r)
  {
    printf("Removed element = %d",q[f]);
    f=-1;
    r=-1;
  }
  else
  {
    printf("Removed element = %d",q[f]);
    f=(f+1)%size;
  }

}

void display()
{
  int i=f;
  if(f==-1 && r==-1)
  printf("Empty\n");
  else 
  {
    while(i!=r)
    {
      printf("%d ",q[i]);
      i=(i+1)%size;
    }
    printf("%d",q[r]);      
  }


}
int main()
{
  int x,n;
  do
  {
    printf("\n\n\t Circular Queue\nChoose one : \n1.Add an element\n2.Remove an element\n3.Display the queue\n4.End \n\nEnter your choice:  ");
    scanf("%d",&x);
    
    switch (x)
    {
    case 1:
    enqueue();
    break;
    
    case 2:
    dequeue();
    break;

    case 3:
    display();
    break;

    default:
    printf("Wrong choice\n");
    break;
    }

  } while (x!=4);
  

}