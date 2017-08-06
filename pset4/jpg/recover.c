/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t  BYTE;

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 1)
    {
        printf("Usage: ./recover \n");
        return 1;
    }
    
    
    FILE* inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", "card.raw");
        return 2;
    }
    
    BYTE buf[512];
   
    int images=0;
    //int index_read=0;
    //int index_written=0;

   
    do
    {
        fread(&buf, sizeof(BYTE),512, inptr);
        //index_read+=1;
    }
    while ((buf[0]!=0xff)||(buf[1]!=0xd8)||(buf[2]!=0xff)||(buf[3]<0xe0)||(buf[3]>0xef));
    
    char* filename= malloc(sizeof(char)*8);
    sprintf(filename, "%03d.jpg",images);
    FILE* outptr=fopen(filename,"w");
    images++;
   
    fwrite(&buf,sizeof(buf),1,outptr);
    fread(&buf, sizeof(BYTE),512, inptr);
    
    do
    {
        //index_read++;
        if ((buf[0]==0xff)&&(buf[1]==0xd8)&&(buf[2]==0xff)&&(0xe0==buf[3]||buf[3]==0xe1))
        {
            fclose(outptr);
            sprintf(filename, "%03d.jpg",images);
            outptr= fopen(filename,"w");
            images++;
        }
        fwrite(&buf,sizeof(buf),1,outptr);
        //index_written+=1;
    }
    while (fread(&buf, sizeof(BYTE),512, inptr)!=0);
    
    //printf("Blocks Written:%d \n", index_written);
    //printf("Blocks Read:%d \n", index_read);
    fclose(inptr);
    fclose(outptr);
    free (filename);
    return 0;
    // TODO
}
