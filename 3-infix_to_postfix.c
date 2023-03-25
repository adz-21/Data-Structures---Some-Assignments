#Converts numeric expressions from infix to postfix form + evaluates the answer

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<limits.h>
#include<math.h>

struct stack1
{
  char data;
  struct stack1 *next;

};
struct stack1 *top=NULL;

int stack2[20];
int top2=-1;

char infix[20];
char postfix[20];

void push(int d)
{
  struct stack1 *temp;
  temp=(struct stack1*)malloc(sizeof(struct stack1));
  temp->data=d;
  temp->next=NULL;
  if(top==NULL)
  {
    top=temp;
  }
  else
  {
    temp->next=top;
    top=temp;
  }
}
char pop()
{
  struct stack *temp;
  char c;
  if(top==NULL)
  printf("Stack is empty\n");
  else if(top->next==NULL)
  {
    temp=top;
    c=top->data;
    top=NULL;
    free(temp);
  }
  else
  {
    temp=top;
    c=top->data;
    top=top->next;
    free(temp);
  }
  return c;
}
int precedence(char o)
{
  switch(o)
  {   
     case '^':
     return 3;
     case '*':
     return 2;
     case '/':
     return 2;
     case '+':
     return 1;
     case '-':
     return 1;
     default:
     return 0;
  }
}
void push1(int d)
{ 
  top2++;
  stack2[top2]=d;
}
int pop1()
{
  int d;
  d=stack2[top2];
  top2--;
  return d;
}
void evaluate(char postfix[])
{
  int i=0,num,n1,n2,n3;
  while(postfix[i]!='\0')
  {
    if(isdigit(postfix[i]))
    {
      num=postfix[i]-48;
      push1(num);
    }
    else
    {
      n1=pop1();
      n2=pop1();
      switch(postfix[i])
      {
         case '+':
         n3=n2+n1;
         push1(n3);
         break;

         case '-':
         n3=n2-n1;
         push1(n3);
         break;

         case '*':
         n3=n2*n1;
         push1(n3);
         break;

         case '/':
         n3=n2/n1;
         push1(n3);
         break;


         case '^':
         n3=pow(n2,n1);
         push1(n3);
         break;

      }
    }
    i++;
  } 
  printf("\nThe evaluated expression : %d",pop1());
}

int main()
{
  char infix[20],postfix[20];
  int i=0,j=0;
  printf("Enter the infix expression : ");
  scanf("%s",infix);

 while(infix[i]!='\0')
 {
   if(isalnum(infix[i]))
   postfix[j++]=infix[i];
   else
   {
      if(top==NULL)
      push(infix[i]);
      else
       {
          while(top!=NULL && precedence(infix[i])<=precedence(top->data))
           postfix[j++]=pop();

          push(infix[i]); 
       }
   }
     i++;
  }
   while(top!=NULL)
   {
    postfix[j++]=pop();
   }
   
  postfix[j]='\0';
  printf("Postfix exp : %s",postfix);

  evaluate(postfix);

}

