// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 500;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{

    int index = hash(word);
    
    node *cursor =  table[index];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == true)
        {
            return true;
        }

        //Move cursor to the next node in the linked list
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int value = 0;
    unsigned int key_len = strlen(word);
    for (int i = 0; i < key_len; i++)
    {
        value = value + 37 * tolower(word[i]); //ascii 
    }

    value = value % N;
    return value;

    //Ref: https://collinsnote.com/cs50-speller-solution-2020-my-explanation/
}


unsigned int count_words = 0;

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return 1;
    }

    char dict_word[LENGTH + 1];
    while (fscanf(file, "%s", dict_word) != EOF)
    {
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            return 2;
        }

        strcpy(newNode->word, dict_word);
        newNode->next = NULL;

        int index = hash(dict_word);

        if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        else
        {
            newNode->next = table[index];
            table[index] = newNode; 
        }
        count_words++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count_words;
    //return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
        return true;
    }

    return false;
}
