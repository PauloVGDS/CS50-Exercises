// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
int count = 0;
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *cursor = table[index];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int index = toupper(word[0]) - 'A';
    if (index > N)
    {
        index = 25;
    }
    return index;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r");
    char word[LENGTH + 1];
    if (dict == NULL)
    {
        return 1;
    }
    while (fscanf(dict, "%s", word) != EOF)
    {
        count++;
        int hashnum = hash(word);
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 2;
        }
        strcpy(n->word, word);
        n->next = table[hashnum];
        table[hashnum] = n;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}


// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int c = 0; c <= N; c++)
    {
        node *cursor = table[c];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}



