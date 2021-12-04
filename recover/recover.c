#include <stdio.h>
#include <stdlib.h>
 

typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover card.raw\n");
        return 1;
    }
    
    FILE *inptr = fopen(argv[1], "r");

    if (inptr == NULL)
    {
        fprintf(stderr, "Invald!");
        return 2;
    }


    int blocksize = 512;
    BYTE buffer[blocksize]; 
    char filename[8];
    int counter = 0;
    FILE *outptr;

    int found = 0;

    
    while (fread(buffer, blocksize, 1, inptr))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            //If already found
            if (found == 1)
            {
                fclose(outptr);
            }
            //First image, set found to 1
            else
            {
                found = 1;
            }

            sprintf(filename, "%03i.jpg", counter);
            outptr = fopen(filename, "w");
            counter++;
        }

        if (found == 1)
        {
            fwrite(buffer, blocksize, 1, outptr);
        }
    }

    fclose(inptr); 
    fclose(outptr);

    return 0;
}
