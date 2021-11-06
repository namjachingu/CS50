#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, string argv[])
{
    int integerLetter;
    string ciphertext;
    string k = argv[1];

    if (argc != 2)
    {
        printf("Only one key is acceptable! \n");
        return 1;
    }

    integerLetter = atoi(k);
    for (int i = 0, n = strlen(k); i < n; i++)
    {   
        //Check if positive integer, and also if input is a digit. 
        if (integerLetter >= 0 && isdigit(k[i]))
        {
            integerLetter = atoi(k);
            string plaintext = get_string("Plaintext: ");
            for (int j = 0; j < strlen(plaintext); j++)
            {
                //Change only alphabetic letters
                if (isalpha(plaintext[j]) != 0)
                {    
                    //Need to first convert letter range, from its original ASCII values, to a range of 0-25 because of modulo. 
                    //After, add the letters back to convert it to ASCII again
                    if (isupper(plaintext[j]))
                    {
                        ciphertext[j] = ((plaintext[j] - 'A') + integerLetter) % 26;
                        ciphertext[i] = ciphertext[i] + 'A';
                    }
                    else
                    {
                        ciphertext[j] = ((plaintext[j] - 'a') + integerLetter) % 26;
                        ciphertext[j] = ciphertext[j] + 'a';
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

        printf("Ciphertext: %s \n", ciphertext);

    }
}


    
