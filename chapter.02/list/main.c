#include <stdio.h>
#include "list.h"


Nameval *create_list()
{
    Nameval *nvlist = NULL;
    nvlist = addfront(nvlist, newitem("wwlee", 30));
    nvlist = addfront(nvlist, newitem("arkim", 24));
    nvlist = addfront(nvlist, newitem("dsjung", 29));
    nvlist = addfront(nvlist, newitem("shjo", 30));
    nvlist = addfront(nvlist, newitem("dhkim", 33));
    
    return nvlist;
}


void test_copy()
{
    Nameval *nvlist = create_list();
    Nameval *copylist = copy(nvlist);
    apply(copylist, printnv, "%s: %d\n");
    
    freeall(nvlist);
    freeall(copylist);
}


void test_merge()
{
    Nameval *nvlist_a = create_list();
    Nameval *nvlist_b = create_list();
    
    Nameval *nvlist_m = merge(nvlist_a, nvlist_b);
    apply(nvlist_m, printnv, "%s: %d\n");
    
    freeall(nvlist_a);
    freeall(nvlist_b);
}


void test_split()
{
    Nameval *nvlist_a = create_list();
    
    Nameval *nvlist_b = split(nvlist_a, "dsjung");
    apply(nvlist_a, printnv, "%s: %d\n");
    printf("- - - - -\n");
    apply(nvlist_b, printnv, "%s: %d\n");
    
    freeall(nvlist_a);
    freeall(nvlist_b);
}


void test_insert_before()
{
    Nameval *nvlist = create_list();
    
    nvlist = insert_before(nvlist, newitem("mhkim", 33), "dsjung");
    apply(nvlist, printnv, "%s: %d\n");
    
    freeall(nvlist);
}


void test_insert_after()
{
    Nameval *nvlist = create_list();
    
    nvlist = insert_after(nvlist, newitem("mhkim", 33), "dsjung");
    apply(nvlist, printnv, "%s: %d\n");
    
    freeall(nvlist);
}


void test_reverse()
{
    Nameval *nvlist = create_list();
    
    Nameval *reverse_list = reverse(nvlist);
    apply(reverse_list, printnv, "%s: %d\n");
    
    freeall(nvlist);
}


int main(int argc, char *argv[])
{
    test_reverse();
    return 0;
}