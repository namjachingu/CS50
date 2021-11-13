## Caesar

Caesar’s algorithm encrypts messages by “rotating” each letter by k positions. More formally, if p is some plaintext (i.e., an unencrypted message),
p_i is the ith character in p, and k is a secret key (i.e., a non-negative integer), then each letter, c_i, in the ciphertext, c, is computed as

c_i = (p_i + k) % 26

wherein % 26 here means “remainder when dividing by 26. 

This program enables you to encrypt messages using Caesar’s cipher. At the time the user executes the program, they should decide, by providing a command-line argument, 
on what the key should be in the secret message they’ll provide at runtime. 

Reference: https://cs50.harvard.edu/x/2021/psets/2/caesar/
