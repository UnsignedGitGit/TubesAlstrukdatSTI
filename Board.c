#include<stdio.h>
#include<conio.h>

void blk(int,int);
void display();


int main()
{
    int i,j,num;
        printf("Enter the number : ");
        scanf("%d",&num);
        for(i=0;i<num;i++)
        {
          for(j=0;j<=num;j++)
          {
             printf("\xDB");
             printf(" ");
           }
             printf("\n");
             if(i%2==0)
             {
                printf(" ");
             }
        }
 getch ();
 return 0;
}
 