#include "stdio.h"
#include "cs50.h"


int main(void)

{

    int height;

    do{
        height = get_int("How tall (1-8 lines) should the pyramid be? \n");
    }
    while(height<1 || height>8);

    int i;
    int j;
    int m;
    int k;

    /*Single sided wall*/
    for(i=0; i<height; ++i)
    {  
        for(j=0; j<height-i-1; ++j)
        {
            printf(" ");
        } 

        for(m=0; m<=i; ++m)
        {
            printf("#");
        };

        printf("\n");
    }
    
    printf("\n \n \n");

    /*Double-sided wall*/
    for(i=0; i<height; ++i)
    {  
        for(j=0; j<height-i-1; ++j)
        {
            printf(" ");
        } 

        for(m=0; m<=i; ++m)
        {
            printf("#");
        };

        printf(" ");

        for(k=0; k<=i; ++k)
        {
            printf("#");
        } 

        printf("\n");
    }

}

