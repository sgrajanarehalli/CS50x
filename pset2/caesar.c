#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc!=2)
    {
    printf("Please enter key value as argument.\n");
    return 1;
    }
    int key = atoi(argv[1]);
    string text=GetString();
    int i;
    for (i=0;i<strlen(text);i++)
    {
        
        if (isupper(text[i]))
        {
            printf("%c", (text[i]-65+key)%26+65);
        }
        else if (islower(text[i]))
        {
            printf("%c", (text[i]-97+key)%26+97);
        }
        else 
        printf("%c", text[i]);
    }
    printf("\n");
}