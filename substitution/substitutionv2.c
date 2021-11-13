#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, string argv[])
{    
    string plaintext = get_string("plaintext: ");
    char ciphertext[strlen(plaintext) + 1];

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters. \n");
        return 1;
 
    }
    if (argc != 2)
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Key must be letters only! \n");
            return 1;
        } 
        else if (argv[1][i] == argv[1][i + 1])
        {
            printf("Key cannot have any repeated characters! \n");
            return 1;           
        }
        else
        {
            for (int j = 0; j < strlen(argv[1]) + 1; j++)
            {        
                if (isalpha(plaintext[j]) && isupper(plaintext[j]))
                {
                    int position = plaintext[j] - 'A';
                    ciphertext[i] = toupper(argv[1][position]); 
                }
                else if(isalpha(plaintext[j]) && islower(plaintext[j]))
                {
                    int position = plaintext[j] - 'a';
                    ciphertext[j] = tolower(argv[1][position]); 
                }
                else
                {
                    ciphertext[j] = plaintext[j];
                }             
            }
        }
    }

    printf("ciphertext: %s\n", ciphertext);  
    return 0;
}
