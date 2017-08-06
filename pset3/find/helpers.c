/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"
#include <math.h>
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n<1)
    return false;
    
   // TODO: implement a searching algorithm
    if (n==1)
    {
        if (values[0]==value)
            {
               return true;
            }
        else
            {
               return false;
            }
    }
    if (n>1)
    {
    int m= floor(n/2);
    if (values[m]==value)
    {
        return true;
    }

    else if (values[m]<value)
    {
        int newset [n-m];
        for (int i=0;i<=m;i++)
        {
            newset[i]=values[i+m];
        }
        n=n-m;
        return (search(value, newset, n)); 
    }
    else if (values[m]>value)
    {
        int newset [n-m];
        for (int i=0;i<=m;i++)
        {
            newset[i]=values[i];
        }
        n=n-m;
        return (search(value, newset, n)); 
        
    }    
    }

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
   int changes;
   do
   {
   changes=0;
    for (int i=0; i<n-1; i++)
    {
        if (values[i]>values[i+1])
        {
            int x=values[i+1];
            values[i+1]=values[i];
            values[i]=x;
            changes++;
        }
    }
    }
    while (changes>0);
    return;
}