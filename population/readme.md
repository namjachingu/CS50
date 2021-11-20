## Population

This program determines how long it takes for a population to reach a particular size.

For example: 

Start size: 100

End size: 200

Years: 9

### Implementation

With a population of n llamas. Each year, n / 3 new llamas are born, and n / 4 llamas pass away.

The program prompts the user for a starting population size. If the user enters a number less than 9 (the minimum allowed population size), the program prompts the user to enter a starting population size until they enter a number that is greater than or equal to 9. (If we start with fewer than 9 llamas, the population of llamas will quickly become stagnant.)
 
Following, the program prompts the user for an ending population size. If the user enters a number less than the starting population size, the user will be re-prompted to enter an ending population size until they enter a number that is greater than or equal to the starting population size. (

Finally, the program calculates the number of years required for the population to reach at least the size of the end value.

Reference: https://cs50.harvard.edu/x/2021/labs/1/population/
