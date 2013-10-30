#include <stdio.h>
#include <stdlib.h>
#include "eprintf.h"


typedef struct Nameval Nameval;
struct Nameval {
    char *name;
    int value;
    Nameval *next; /* 다음 아이템을 가리킴 */
};


Nameval *newitem(char *name, int value);
Nameval *addfront(Nameval *listp, Nameval *newp);
Nameval *addend(Nameval *listp, Nameval *newp);
Nameval *lookup(Nameval *listp, char *name);
void apply(Nameval *listp, void (*fn)(Nameval*, void*), void *arg);
void printnv(Nameval *p, void *arg);
void inccounter(Nameval *p, void *arg);
void freeall(Nameval *listp);
Nameval *delitem(Nameval *listp, char *name);
Nameval *copy(Nameval *src);
Nameval *merge(Nameval *a, Nameval *b);
Nameval *split(Nameval *listp, const char *name);
Nameval *insert_before(Nameval *listp, Nameval *newp, const char *name);
Nameval *insert_after(Nameval *listp, Nameval *newp, const char *name);
Nameval *reverse(Nameval *listp);
