/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "dictionary.h"

/**
 * Returns true if word is in dictionary else false.
 */


node* root;

unsigned int words_loaded=0;
unsigned int mallocs=0;
unsigned int frees=0;

bool check(const char* word)
{
    char current_word [46];
    for (int i=0; i<=strlen(word); i++)
    {
        current_word[i]=tolower(word[i]);
    }
    int end= strlen(current_word)-1;

    node* cursor=root;
    
    for (int i=0; i<=end; i++)
    {
        int index;
        if (isalpha(current_word[i]))
        {
            index=current_word[i]-97;;
        }
        else
        {
            index=26;
        }
            
        if (cursor->children[index])
        {
            if (i==end&&!cursor->children[index]->is_word)
            {
                return false;
            }
            cursor=cursor->children[index];
        }
        else
        {
            return false;
        }
    }
    return true;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    root=malloc(sizeof(node));
    mallocs++;
    
    //Open dictionary and scan words to char*
    FILE* dict=fopen(dictionary,"r");
    char current_word[46];
    for (int i=0; i<46; i++)
    {
        current_word[i]='\0';
    }
    while (fscanf(dict, "%s", current_word)!=EOF)
    
    {
        //create a cursor and initialize it to the root
        node* cursor=root;
        unsigned int index;
        int end=strlen(current_word)-1;
        for (int i=0;i<=end;i++)
        {
            if (isalpha(current_word[i]))
            {
                index=current_word[i]-97;
            }
            else
            {
                index=26;
            }

            //if current_word[i] is a letter and the child node corresponding to that letter exists
            if (cursor->children[index])
            {
                if (i==end) //if last letter of word
                {
                    cursor->children[index]->is_word=true; //change children[].is_word to true
                }
                cursor=cursor->children[index]; //move cursor forward
                
            }

            //if current_word[i] is a letter and a child node for that letter doesn't already exist.
            else if (!cursor->children[index])
            {
                //malloc a new node
                node* new_node= malloc(sizeof(node));
                mallocs++;
                
                //if last letter change new node's is_word value to true
                if (i==end)
                {
                    new_node->is_word=true;
                }
                
                cursor->children[index]=new_node; //insert new node
                cursor=cursor->children[index];
            }
        }
                
        words_loaded++;
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
    free_node(root);
    if (mallocs!=frees)
    {
        return false;
    }
    return true;
}

bool free_node(node* root)
{
    for (int i=0; i<27; i++)
    {
        if (root->children[i])
        {
            free_node(root->children[i]);
        }
    }
    frees++;
    free(root);
    return true;
}