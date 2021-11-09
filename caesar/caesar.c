#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    int integerLetter;
    char ciphertext[strlen(plaintext) + 1];
    string k = argv[1];

    if (argc != 2)
    {
        printf("Only one key is acceptable! \n");
        return 1;
    }

    integerLetter = atoi(k);
    for (int i = 0; i < strlen(k) + 1; i++)
    {   
        //Check if positive integer, and also if input is a digit. 
        if (integerLetter >= 0 && isdigit(k[i]))
        {
            integerLetter = atoi(k);
            string plaintext = get_string("plaintext: ");
            for (int j = 0; j < strlen(plaintext) + 1; j++)
            {
                //Change only alphabetic letters
                if (isalpha(plaintext[j]))
                {    
                    //Need to first convert letter range, from its original ASCII values, to a range of 0-25 because of modulo. 
                    //After, add the letters back to convert it to ASCII again
                    if (isupper(plaintext[j]))
                    {
                        ciphertext[j] = ((plaintext[j] - 'A') + integerLetter) % 26 + 'A';
                    }
                    else
                    {
                        ciphertext[j] = ((plaintext[j] - 'a') + integerLetter) % 26 + 'a';
                    }
                }
                else
                {
                    ciphertext[j] = plaintext[j];
                }
            }
        }
        else
        {
            printf("Usage: ./caesar key \n");
            return 1;
        }

        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
}
