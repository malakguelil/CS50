// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

#define HASHTABLE_SIZE 10000

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;


// Hash table
node *hashtable[HASHTABLE_SIZE];

// Hashes word to a number
unsigned int hash_index( char *hash_this)
{
   unsigned int hash = 0;
     for (int i = 0;i < strlen(hash_this); i++) {
         hash = (hash << 2) ^ hash_this[i];
     }
    return hash % HASHTABLE_SIZE;
}
int word_count = 0;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{  
    FILE *file = fopen(dictionary, "r");
    if (file == NULL) {
    return false;
   }  
   char word[LENGTH + 1];
   while (fscanf(file, "%s", word) != EOF) {
       node *new_node = malloc(sizeof(node));
       if (new_node == NULL) {
           unload();
           return false;
       }
     strcpy(new_node->word, word);
     int h = hash_index(new_node->word);
    node *head = hashtable[h];
    if (head == NULL) {
        hashtable[h] = new_node;
        word_count++;
    } else    {
         new_node->next = hashtable[h];
         hashtable[h] = new_node;
         word_count++;
   }
     }
    fclose(file);
    return true;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int n = strlen(word);
    char word_copy[LENGTH + 1];
    for (int i = 0; i < n; i++) {
        word_copy[i] = tolower(word[i]);
    }
    word_copy[n] = '\0';
    int h = hash_index(word_copy);
    node *cursor = hashtable[h];
       while (cursor != NULL) {
               if(strcmp(cursor->word, word_copy) == 0) {
                   return true;
} else {
    cursor = cursor->next;
}}
           return false;
       }
 


   
// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
     node *head = NULL;
     node *cursor = head;
     while (cursor != NULL) {
         node *temp = cursor;
         cursor = cursor->next;
         free(temp);
     }
    return true;
}
