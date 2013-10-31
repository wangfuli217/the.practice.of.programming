#include <stdio.h>
#include <stdlib.h>
#include "eprintf.h"


typedef struct Nameval Nameval;
struct Nameval {
    char *name;
    int value;
    Nameval *left;      /* lesser: 작은 값을 갖는 노드 */
    Nameval *right;     /* greater: 큰 값을 가즌ㄴ 노드 */
};


Nameval *newitem(char *name, int value);
void printnv(Nameval *p, void *arg);
void freeall(Nameval *listp);

Nameval *insert(Nameval *treep, Nameval *newp);
Nameval *lookup(Nameval *treep, char *name);
Nameval *nrlookup(Nameval *treep, char *name);
void applyinorder(Nameval *trepe, void (*fn)(Nameval*, void*), void *arg);
void applypostorder(Nameval *treep, void (*fn)(Nameval*, void*), void *arg);
