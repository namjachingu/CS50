
#include "stdio.h"
#include "cs50.h"
#include "math.h"

int main(void)
{
    int start;

    do
    {
        start = get_int("Enter starting population size: \n");
    }
    while (start < 9); 
    
    printf("Start: %i\n", start);


    int end;

    do
    {
        end = get_int("Enter ending population size: \n"); 
    }
    while(end < start);

    printf("End: %i\n", end);


    int born = start/3;
    printf("Born: %i\n", born);
    int dead = start/4;
    printf("Dead: %i\n", dead);
    int llamas = start + born - dead;

    printf("Llamas: %i\n",llamas);

    int years = 1; 

    while(llamas < end)
    {
        years = years + 1;
        llamas = llamas + llamas/3 - llamas/4;
    }
    printf("Years: %i \n", years);


}
