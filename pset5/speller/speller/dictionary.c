// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

//Global int for counting the size of the dictionary:
int wordCount = 0;

// Hash table
node *table[N];

//Index
unsigned int hasher;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //Hash word to find index of linked list
    hasher = hash(word);

    //Access the bucket
    node *cursor = table[hasher];

    //Use strcasecmp to compare words without case sensitivity
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor -> word) == 0)
        {
            return true;
        }
        cursor = cursor -> next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;
    while ((c = toupper(*word++)))
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //Open file
    FILE *file = fopen(dictionary, "r");

    //Check file is valid
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }

    //Initialize char word
    char word[LENGTH + 1];

    //Read word individually
    while (fscanf(file, "%s", word) != EOF)
    {

        //Allocate memory for note
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        //String copy to node|word
        strcpy(n -> word, word);

        //Find index of hash table
        hasher = hash(word);

        //Insert node at the head of the linked list
        n -> next = table[hasher];

        //Make the new node the head of the linked list
        table[hasher] = n;

        //Increase word counter
        wordCount++;

    }

    //Close file
    fclose(file);
    return true;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (wordCount > 0)
    {
        return wordCount;
    }
    else
    {
        return false;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //free memory by recycling the node in a while loop
    for (int i = 0; i < N; i ++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor -> next;
            free(temp);
        }

        //When cursor is at the last bucket and the end of the linked list
        if (i == N - 1 && cursor == NULL)
        {
            return true;
        }
    }
    return false;

}
