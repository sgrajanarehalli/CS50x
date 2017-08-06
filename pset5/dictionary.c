/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"
#include "GeneralHashFunctions.h"
/**
 * Returns true if word is in dictionary else false.
 */
 
node* hashtable[8192];
unsigned int words_loaded=0;
unsigned int mallocs=0;
unsigned int frees=0;
bool check(const char* word)
{
    // TODO
    unsigned int i=0;
    char* current_word=malloc(sizeof(char)*46);
    mallocs++;
    while (word[i])
    {
        current_word[i]=tolower(word[i]);
        i++;
    }
    while (i<46)
    {
        current_word[i]='\0';
        i++;
    }
    unsigned int index= FNVHash(current_word,4)%8192;
    node*cursor=hashtable[index];
    while (cursor!=NULL)
    {
        if(strcmp(cursor->word, current_word)==0)
        {
            free(current_word);
            frees++;
            return true;
        }
        else
        {
            cursor=cursor->next;
        }
    }
    free(current_word);
    frees++;
    return false;
    
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    unsigned int index;
    
    FILE* dict=fopen(dictionary,"r");
    if (dict==NULL)
    {
        return false;
    }
   
    char current_word [46];
    while (fscanf(dict, "%s", current_word)!=EOF)
    {

        node* new_node= malloc(sizeof(node));
        mallocs++;
        
        strcpy(new_node->word,current_word);
        
        new_node->next=NULL;
        index=FNVHash(new_node->word,4)%8192;
        
        node*cursor=hashtable[index];
        if (hashtable[index]==NULL)
        {
            hashtable[index]=new_node;
        }
        else
        {
            do
            {
                if (cursor->next==NULL)
                {
                    cursor->next=new_node;
                }
                else
                {
                    cursor=cursor->next;
                }
            }
            while (cursor->next!=new_node);
        }
        words_loaded++;
        for (int i=0; i<46; i++)
        {
            current_word[i]='\0';
        }
        
    }
    fclose(dict);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return words_loaded;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    for (int i=0; i<8192; i++)
    {
        node* cursor=hashtable[i];
        while (cursor!=NULL)
        {
            node* temp=cursor;
            cursor=cursor->next;
            free(temp);
            frees++;
        }
    }
    if (mallocs!=frees)
    {
        return false;
    }
    return true;
}
