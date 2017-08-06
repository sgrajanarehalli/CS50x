#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int m;
    do
    { 
       printf("minutes: ");
       m=GetInt();
    }
    while (m<1);
    m=m*12;
    printf("bottles: %i\n", m);
} 