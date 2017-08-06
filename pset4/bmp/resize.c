/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP and scales it up by a resize factor.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }
    
    int resize_factor= atoi(argv[1]);
    if (resize_factor<1||resize_factor>100)
    {
        printf("Resize factor must be an interger from 1 to 100.\n");
        return 2;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    
    BITMAPFILEHEADER bfOut;
    bfOut=bf;
    

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    BITMAPINFOHEADER biOut;
    biOut=bi;
    
    // update headers
    biOut.biWidth= resize_factor*bi.biWidth;
    biOut.biHeight=resize_factor*bi.biHeight;
    
    long padding_old= (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    long padding_new =  (4 - (biOut.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    biOut.biSizeImage= (biOut.biWidth * sizeof(RGBTRIPLE) +padding_new)*abs(biOut.biHeight);
    bfOut.bfSize= biOut.biSizeImage+ sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write outfile's BITMAPFILEHEADER
    fwrite(&bfOut, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&biOut, sizeof(BITMAPINFOHEADER), 1, outptr);
 


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
    for (int counter=0; counter<resize_factor;counter++) //repeat each scanline n times
    {
        long scanline_start= ftell(inptr);
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;
            
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            for (int h=0; h<resize_factor; h++) // write each pixel n times
            {
                // write RGB triple to outfile
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        }

        
        
        // skip over padding, if any
        fseek(inptr, padding_old, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding_new; k++)
        {
            fputc(0x00, outptr);
        }
        
    if (counter<resize_factor-1) //go back to the start of the scanline
        {
            fseek(inptr,scanline_start,SEEK_SET);
        }
    }
    }
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
