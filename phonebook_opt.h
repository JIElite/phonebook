#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define HASH_TABLE_SIZE 20809 

struct __PHONE_DETAILS{
    char state[2];
    char zip[5];
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
};


/* original version */
typedef struct __PHONE_LAST_NAME {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_DETAILS *detail;
    struct __PHONE_LAST_NAME *pNext;
} entry;

extern entry *hash_table[HASH_TABLE_SIZE];
extern entry *hash_entry[HASH_TABLE_SIZE];


entry *findName(char lastname[], entry *pHead);
entry *append(char lastName[], entry *e);
void free_structure(void *);

#endif
