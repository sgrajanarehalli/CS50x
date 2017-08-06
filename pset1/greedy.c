#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{
    float change;
    do
    {
    printf("How much change?\n");
    change= GetFloat();
    }
    while (change<0);
    change=change*100;
    change= (int) round(change);
    int coins;
    coins=0;
    if (change>0)
    {
        while (change>=25)
        {
            change=change-25;
            coins=coins+1;
        }
        while (change<25&&change>=10)
        {
            change=change-10;
            coins=coins+1;
        }
        while (change<10&&change>=5)
        {
            change=change-5;
            coins= coins+1;
        }
       while(change<5&&change>0)
        {
            change=change-1;
            coins=coins+1;
        }
    }
    printf("%i\n",coins);
}