#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
string name= GetString();
for (int i=0; i<strlen(name); i++)
    {
        if ((i==0||name[i-1]==32)&&isalpha(name[i]))
        
         {
            if (isupper(name[i]))
            {
                printf("%c",name[i]);
            }
            else
            {
                printf("%c",name[i]-32);
            }
         }
    }
    printf("\n");
}