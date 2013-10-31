#include <stdio.h>
#include "tree.h"


void test_insert()
{
    Nameval *treep;
    treep = NULL;

    treep = insert(treep, newitem("wwlee", 30))
    treep = insert(treep, newitem("arkim", 24))


    applyinorder(treep, printnv, "%s: %d\n");
    freeall(treep);
}


int main(int argc, char *argv[])
{
    test_insert();
    return 0;
}
