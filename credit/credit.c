#include "stdio.h"
#include "cs50.h"
#include "math.h"

int main(void)
{   
    long cardNumber = get_long("What is your credit card number?\n");
    long cardNumberOdd;
    long cardNumberEven;
    long cardNumberCounter;

    cardNumberOdd = cardNumber / 10;
    cardNumberEven = cardNumber;
    cardNumberCounter = cardNumber;

    int digit; 
    int sum = 0;
    int seperator = 0;

    //Count digits in card number
    int counter = 0;
    do
    {   
        cardNumberCounter = cardNumberCounter / 10;
        counter++;
    } 
    while (cardNumberCounter != 0); 

    //Iterate through every other digit, starting from the second to last in the back
    do
    {
        digit = cardNumberOdd % 10;
        cardNumberOdd = cardNumberOdd / 100;

        if (digit * 2 > 9)
        {
            seperator = seperator + ((digit * 2) / 10) + ((digit * 2) % 10);
        }
        else
        {
            seperator = seperator + digit * 2;
        }
        sum = (sum + digit * 2);
    }
    while (cardNumberOdd > 0);
    
    //Checksum
    int sum2 = 0;
    do
    {
        digit = cardNumberEven % 10;
        cardNumberEven = cardNumberEven / 100; 
        sum2 = (sum2 + digit);
    }
    while (cardNumberEven > 0);
    
    int sum3 = seperator + sum2;

    int isValid = sum3 % 10;

    //Print two first digits of card number
    do
    {
        cardNumber = cardNumber / 100; 
    }
    while (cardNumber > 100);

 
    //Validate if card is legimate or not
    if (isValid == 0)
    {
        if (counter == 15 && (cardNumber == 34 || cardNumber == 37))
        {   
            printf("AMEX \n");
        }
        else if (counter == 16 && (cardNumber > 50 && cardNumber < 56))
        {
            printf("MasterCard \n");
        }
        else if ((counter == 13 || counter == 16) && (cardNumber / 10 == 4)) 
        {   
            printf("VISA \n");
        }
    }
    else 
    {
        printf("The card is invalid! \n");
    }
}
