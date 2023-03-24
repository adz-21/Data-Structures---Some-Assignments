#include<stdio.h>
#include<stdlib.h>

void display(int *t)
{ 
    int i,j;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      printf("%d\t",*(t+i*3+j)); 
    }
    printf("\n");
   }
}

int main()
{
    int a[3][3],b[3][3],sum[3][3],pro[3][3];
    int *p;
    int*q;
    int *r,*s;
    p=&a[0][0];
    q=&b[0][0];
    r=&sum[0][0];
    s=&pro[0][0];

    int x,i,j,k,mul;
    int min_row=0,max=0,ci=0,flag=0;
  //Matrix 1
   printf("\nEnter the values of matrix 1 : \n");
   for(i=0;i<3;i++)
   {
    printf("Row %d :\n",i+1);
    for(j=0;j<3;j++)
    {
      printf("Column %d : ",j+1);
      scanf("%d",(p+i*3+j)); 

    }
   }
   //Matrix 2
   printf("\nEnter the values of matrix 2 : \n");
   for(i=0;i<3;i++)
   {
    printf("Row %d :\n",i+1);
    for(j=0;j<3;j++)
    {
      printf("Column %d : ",j+1);
      scanf("%d",(q+i*3+j)); 
    }
   }

    do
   {
      printf("\n\nEnter the operation you'd like to perform : \n1.Addition\n2.Multiplication\n3.Transpose\n4.Saddle Point\n5.Quit\n");
      printf("Enter your choice : ");
      scanf("%d",&x);
      switch(x)
      {
        case 1:
        // addition
         for(i=0;i<3;i++)
        {
         for(j=0;j<3;j++)
         {
          *(r+i*3+j)= *(p+i*3+j) + *(q+i*3+j);
         }    
         }
        printf("\nMatrix 1 :\n");
        display(p);
        printf("\nMatrix 2 :\n");
        display(q);
        printf("\nSum :\n");
        display(r);
        break;
 
         case 2:
           // multiplication
           for(i=0;i<3;i++)
           {
             for(j=0;j<3;j++)
             {
                mul=0;
                for(k=0;k<3;k++)
                {
                  mul= mul + (*(p+i*3+k))*( *(q+k*3+j));
                }
                *(s+i*3+j)=mul;
             } 
           }
           printf("\nMatrix 1 :\n");
           display(p);
            printf("\nMatrix 2 :\n");
            display(q);
           printf("Product of the 2 matrices : \n");
           display(s);
           break;

    
    case 3:
   // transpose
    printf("\nTranspose of Matrix 1 : \n");
     for(j=0;j<3;j++)
     {
       for(i=0;i<3;i++)
      {
         printf("%d\t",*(p+i*3+j)); 
       }
       printf("\n");
     }
     printf("\nTranspose of Matrix 2 : \n");
     for(j=0;j<3;j++)
     {
       for(i=0;i<3;i++)
      {
         printf("%d\t",*(q+i*3+j)); 
       }
       printf("\n");
     }

    break;

    case 4:
      // saddle point- min in the row and max in the row
     printf("\nFor Matrix 1 : \n");
     for(i=0;i<3;i++)
     {
        min_row=*(p+i*3+j);
        for(j=0;j<3;j++)
        {
          if(min_row > *(p+i*3+j))
          {
            min_row=*(p+i*3+j);
            ci=j;
          }
        }
        max=min_row;
        for(k=0;k<3;k++)
        {
          if(max<*(p+k*3+ci))
          max=*(p+k*3+ci);
        }
        
        if(max==min_row)
        {
            printf("\nSaddle Point = %d\n",max);
            flag=1;
        }
     }   
     if(flag==0)
     printf("\nNO SADDLE POINT\n");
 
    break;

    case 5:
    break;
    
    default:
    printf("Wrong choice\n");
   }
 } while (x!=5);
}