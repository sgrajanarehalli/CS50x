#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int shiftChar(char c);
int main(int argc, string argv[])
{
    string key=argv[1];
    int k;
    
    if (argc!=2)
    {
        printf("Please enter keyword as argument.\n");
        return 1;
    }
    for (k=0;k<strlen(key);k++)
    {
        if (!isalpha(key[k]))
        {
            printf("Keyword must contain only letters.\n");
            return 1;
        }
    }
    
    string text=GetString();
    int i;
    int j=0;
    for (i=0;i<strlen(text);i++)
    {
        
        if (isupper(text[i]))
        {   
            int shift;
            shift=shiftChar(key[j%strlen(key)]);
            printf("%c", (text[i]-65+shift)%26+65);
            j++;
        }
        else if (islower(text[i]))
        {   
            int shift;
            shift=shiftChar(key[j%strlen(key)]);
            printf("%c", (text[i]-97+shift)%26+97);
            j++;
        }
        else 
        {
        printf("%c", text[i]);
        }
    }
    printf("\n");
}
int shiftChar(char c)
{
    int shift;
    if (isupper(c))
        shift= c-65;
    else
        shift= c-97;
    return shift;
}