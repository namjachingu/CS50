## Credit

The printed number on a credit card is stored in a database somewhere, so that when your card is used to buy something, the creditor knows whom to bill. Credit card companies use a set of numbers that define their cards. American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers. The credit card numbers also have some structure to them. All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern ourselves with for this problem); and all Visa numbers start with 4. But credit card numbers also have a “checksum” built into them, a mathematical relationship between at least one number and others. That checksum enables computers to detect typos (e.g., transpositions), if not fraudulent numbers, without having to query a database, which can be slow. A database would still be necessary though for more rigorous checks.

### Luhn’s Algorithm

Most cards use Luhn’s algorithm to determine if a credit card number is (syntactically) valid as follows:

1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
2. Add the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

Here is an example with a Visa card: 4003600000000014.

Multiply each of the underlined digits by 2: 1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2

That gives us: 2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

Add those products’ digits (i.e., not the products themselves) together: 2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

Add that sum (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end): 13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20

The last digit in that sum (20) is a 0, so the card is legit.

### Implementation

The program prompts the user for a credit card number and then reports whether it is a valid American Express, MasterCard, or Visa card number. 

Reference: https://cs50.harvard.edu/x/2021/psets/1/credit/
