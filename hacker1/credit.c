#include <stdio.h>
#include <cs50.h>
#include <math.h>
int CheckSum(long long c);
int len(long long c);
int main(void)
{
    long long card;
    printf("Please enter card number.\n");
    card=GetLongLong();
    //printf("%d\n",len(card)); //sanity check
    //printf("%d\n",CheckSum(card)); //sanity check
    if (CheckSum(card)%10==0)
   {
       if (len(card)==15)
       {
           while (card>100)
           {
               card=floor(card/10);
           }
           if (card==34||card==37)
           {
               printf("AMEX\n");
           }
       }
       else if (len(card)==13)
       {
           while (card>10)
           {
               card=floor(card/10);
           }
           if (card==4)
           {
               printf("VISA\n");
           }
       }
       else if (len(card)==16)
       {
           while (card>100)
           {
               card=floor(card/10);
           }
           if (card>=51&&card<=55)
           {
               printf("MASTERCARD\n");
           }
           else if (floor(card/10)==4)
           {
               printf("VISA\n");
           }
       }
    }
    else
    {
        printf("INVALID\n");
    }
}
int CheckSum(long long n)
{   
    int sum;
    sum=0;
    while (n>0)
    {
        sum=sum+(n%10);
        n= floor(n/10);
        if (2*(n%10)<10)
        {
            sum= sum+ 2*(n%10);
        }
        else
        {
            sum=sum+floor(2*(n%10))/10;
            sum=sum+((2*(n%10))%10);
        }
        n=floor(n/10);
    }
    return sum;
}
int len(long long n)
{
    int len;
    len=0;
    while (n>0)
    {
        len=len+1;
        n=floor(n/10);
    }
    return len;
}