#include <stdio.h>
#include <cs50.h>
int main(void)
{
    int h;
    do
    { 
       printf("height: ");
       h=GetInt();
    }
    while (h>23||h<0);
 int i;
 for (i=1; i<=h; i=i+1)
 {
    int k;
    k=0;
    while (k<h-i)
        {
             printf(" ");
             k=k+1;
        }
   
     int j;
     j=1;
     while (j<=i)
     {
        printf("#");
        j=j+1;
     }
     printf("  ");
     j=1;
      while (j<=i)
     {
        printf("#");
        j=j+1;
     }
     printf("\n");
 }
}