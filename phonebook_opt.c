#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"


entry *hash_table[HASH_TABLE_SIZE];
entry *hash_entry[HASH_TABLE_SIZE];


static inline int hash(char lastname[]){
    const unsigned char *name = (const unsigned char *)lastname;
    unsigned int h = 5381;
    int ch;

    while ((ch = *name++) != '\0')
        h = (h << 5) + h + ch;
    
    return h % HASH_TABLE_SIZE;
}

entry *findName(char lastname[], entry *pHead)
{
    int hash_value = hash(lastname);
    pHead = hash_table[hash_value];

    while (pHead) {
        if (strcmp(pHead->lastName, lastname) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
        
    return NULL;

}


entry *append(char lastname[], entry *e)
{
    int hash_value = hash(lastname);
    entry *new_node = (entry *)malloc(sizeof(entry));

    if (hash_table[hash_value] == NULL){
        new_node->pNext = NULL;
        strcpy(new_node->lastName, lastname);
        hash_table[hash_value] = new_node;
        hash_entry[hash_value] = new_node;
        return new_node;
    }
    
    hash_entry[hash_value]->pNext = new_node;
    strcpy(new_node->lastName, lastname);
    new_node->pNext = NULL;
    hash_entry[hash_value] = new_node;
    return new_node;
}
