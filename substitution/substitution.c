#include <cs50.h>
#include <stdio.h>
#include "string.h"
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    string ciphertext;
    
    
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters. \n");
        return 1;
 
    }
    else if (argc != 2)
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }

    for(int i=0; i<strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Key must be letters only! \n");
            return 1;
        } 
        
        /*
        for(int j = 0; j<strlen(argv[1]); j++)
        {
            if(argv[1][j+1] == argv[1][i])
            {
            printf("Key cannot have any repeated characters! \n");
            return 1;
            }
        }
        */
       if(argv[1][i] == argv[1][i+1])
       {
            printf("Key cannot have any repeated characters! \n");
            return 1;           
       }
    }
 

    string plaintext = get_string("plaintext: ");
    printf("plain: %lu\n", strlen(plaintext));
    for(int i = 0; i < strlen(plaintext); i++)
    {        
        if (isalpha(plaintext[i]) && isupper(plaintext[i]))
        {
            ciphertext[i] = plaintext[i] - 'A'; //FEIL HER
            printf("char: %c\n",ciphertext[i]);
            ciphertext[i] = argv[1][ciphertext[i]]; 
        }
        else if (isalpha(plaintext[i]) && islower(plaintext[i]))
        {
            ciphertext[i] = plaintext[i] - 'a'; //FEIL HER
            printf("char: %c\n",ciphertext[i]);
            ciphertext[i] = argv[1][ciphertext[i]]; 
        }    
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    printf("ciphertext: %s", ciphertext);  
}
