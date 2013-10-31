#include "tree.h"


/* newitem: 주어진 name과 value로 새 아이템을 만듦 */
Nameval *newitem(char *name, int value)
{
    Nameval *newp;
    
    newp = (Nameval *) emalloc(sizeof(Nameval));
    newp->name = name;
    newp->value = value;
    newp->left = NULL;
    newp->right = NULL;
    return newp;
}


/* printnv: 인자로 받은 출력 형식으로 name과 value 출력 */
void printnv(Nameval *p, void *arg)
{
    char *fmt;
    
    fmt = (char *) arg;
    printf(fmt, p->name, p->value);
}


/* freeall: listp의 모든 아이템에 대한 메모리 할당 해제 */
void freeall(Nameval *treep)
{
    if (NULL == treep)
        return;
    freeall(treep->left);
    freeall(treep->right);
    free(treep);
}


/* insert: newp를 treep에 추가하고 treep를 리턴 */
Nameval *insert(Nameval *treep, Nameval *newp)
{
    int cmp;

    if (NULL == treep)
        return newp;
    cmp = strcmp(newp->name, treep->name);
    if (0 == cmp)
        weprintf("insert: duplicate entry %s ignored",
            newp->name); /* 중복된 값은 무시 */
    else if (0 > cmp)
        treep->left = insert(treep->left, newp);
    else
        treep->right = insert(treep->right, newp);
    return treep;
}


/* lookup: treep 트리에서 name을 검색 */
Nameval *lookup(Nameval *treep, char *name)
{
    int cmp;

    if (NULL == treep)
        return NULL;
    cmp = strcmp(name, treep->name);
    if (0 == cmp)
        return treep;
    else if (0 > cmp)
        return lookup(treep->left, name);
    else
        return lookup(treep->right, name);
}


/* nrlookup: 비재귀적으로 treep 트리에서 name을 검색 */
Nameval *nrlookup(Nameval *treep, char *name)
{
    int cmp;

    while (NULL != treep) {
        cmp = strcmp(name, treep->name);
        if (0 == cmp)
            return treep;
        else if (0 > cmp)
            treep = treep->left;
        else
            treep = treep->right;
    }
    return NULL;
}


/* applyinorder: treep에 fn을 중위 순회법으로 적용 */
void applyinorder(Nameval *treep, void (*fn)(Nameval*, void*), void *arg)
{
    if (NULL == treep)
        return;
    applyinorder(treep->left, fn, arg);
    (*fn)(treep, arg);
    applyinorder(treep->right, fn, arg);
}


/* applypostorder: treep에 fn을 후위 순회법으로 적용 */
void applypostorder(Nameval *treep, void (*fn)(Nameval*, void*), void *arg)
{
    if (NULL == treep)
        return;
    applypostorder(treep->left, fn, arg);
    applypostorder(treep->right, fn, arg);
    (*fn)(treep, arg);
}


/* treesort: 이름 순서대로 정렬 */
void treesort(Nameval *treep, int *p, char *names[])
{
    if (NULL == treep)
        return;
    treesort(treep->left, p, names);
    names[*p] = treep->name;
    *p += 1;
    treesort(treep->right, p, names);
}
