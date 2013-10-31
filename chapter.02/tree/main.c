#include <stdio.h>
#include "tree.h"


void test_insert()
{
    Nameval *treep;
    treep = NULL;

    treep = insert(treep, newitem("dsjung", 29));
    treep = insert(treep, newitem("wwlee", 30));
    treep = insert(treep, newitem("arkim", 24));
    treep = insert(treep, newitem("shjo", 31));
    treep = insert(treep, newitem("dhkim", 33));

    applyinorder(treep, printnv, "%s: %d\n");
    freeall(treep);
}


void test_treesort()
{
    Nameval *treep;
    int i = 0;
    int p = 0;
    char *names[10] = {NULL};
    
    treep = NULL;
    treep = insert(treep, newitem("dsjung", 29));
    treep = insert(treep, newitem("wwlee", 30));
    treep = insert(treep, newitem("arkim", 24));
    treep = insert(treep, newitem("shjo", 31));
    treep = insert(treep, newitem("dhkim", 33));
    
    treesort(treep, &p, names);
    
    for (i = 0; i < 5; ++i) {
        if (NULL == names[i])
            break;
        printf("%s\n", names[i]);
    }
    
    freeall(treep);
}


int main(int argc, char *argv[])
{
    test_treesort();
    return 0;
}
