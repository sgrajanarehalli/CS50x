#define _XOPEN_SOURCE
#define _GNU_SOURCE 
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>
#include <zlib.h>


bool checkdict(const char* password);
bool increment (char* word, const char* password, int index, int len);

int main (int argc, string argv[])
{
    char* passwd=argv[1];
    if (checkdict(passwd))
    {
        return true;
    }

    char test [8];
    
    for (int j=1; j<=8; j++)
    {
        
        for (int i=0; i<8; i++)
        {
            test[i]='\0';
        }
        if (increment (test, passwd, 0, j))
        {
            return true;
        }
    
    }
    printf("Could not crack password.");
    return false;
}

bool increment (char* word, const char* password, int index, int len)
{
    char salt[2];
    strncpy(salt,password,2);
    word[index]=65;
   
    
    while (word[index]<123)
    {
        if (index+1<len)
        {
            if(increment(word,password, index+1,len))
            {
                return true;
            }
        
        }
        if (strcmp(crypt(word,salt),password)==0)
        {
            printf("%s\n", word);
            return true;
        }
        if (word[index]==90)
        {
            word[index]=97;
        }
        else
        {
        word[index]++;
        }
    }
    return false;
}

    
    
bool checkdict(const char* password)
{
    char word [255];
    char salt[2];
    strncpy(salt,password,2);
    unsigned long long index=0;
    FILE *dict = fopen("/usr/share/dict/words", "r");
    while (fgets(word, 255, dict))
    {
        if (strlen(word) <=4 && strcmp(crypt(word, salt), password) == 0)
        {
            printf("%s", word);
            return 0;
        }
       index++;
    }
    fclose(dict);
    return false;
}