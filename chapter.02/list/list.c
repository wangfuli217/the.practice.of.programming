#include "list.h"


/* newitem: 주어진 name과 value로 새 아이템을 만듦 */
Nameval *newitem(char *name, int value)
{
    Nameval *newp;
    
    newp = (Nameval *) emalloc(sizeof(Nameval));
    newp->name = name;
    newp->value = value;
    newp->next = NULL;
    return newp;
}


/* addfront: newp를 listp의 앞쪽에 추가. */
Nameval *addfront(Nameval *listp, Nameval *newp)
{
    newp->next = listp;
    return newp;
}


/* addend: newp를 listp의 끝에 추가 */
Nameval *addend(Nameval *listp, Nameval *newp)
{
    Nameval *p;
    
    if (listp == NULL)
        return newp;
    
    for (p = listp; p->next != NULL; p = p->next)
        ;
    p->next = newp;
    
    return listp;
}


/* lookup: listp에서 이름을 선형 검색으로 찾는다 */
Nameval *lookup(Nameval *listp, char *name)
{
    for (; listp != NULL; listp = listp->next) {
        if (strcmp(name, listp->name) == 0)
            return listp;
    }
    return NULL;        /* 일치하는 것이 없음 */
}


/* apply: listp의 원소마다 fn을 실행 */
void apply(Nameval *listp,
        void (*fn)(Nameval*, void*), void *arg)
{
    Nameval *first = listp;
    for ( ; listp != NULL; listp = listp->next)
        (*fn) (listp, arg);     /* 함수 호출 */
}


/* printnv: 인자로 받은 출력 형식으로 name과 value 출력 */
void printnv(Nameval *p, void *arg)
{
    char *fmt;
    
    fmt = (char *) arg;
    printf(fmt, p->name, p->value);
}


/* inccounter: 카운터 *arg를 하나씩 늘림 */
void inccounter(Nameval *p, void *arg)
{
    int *ip;
    
    /* p는 쓰이지 않음 */
    ip = (int *) arg;
    (*ip)++;
}


/* freeall: listp의 모든 아이템에 대한 메모리 할당 해제 */
void freeall(Nameval *listp)
{
    Nameval *next;
    
    for ( ; listp != NULL; listp = next) {
        next = listp->next;
        /* name은 다른 곳에서 해제되었다고 가정함 */
        free(listp);
    }
}


/* delitem: listp에서 처음으로 나오는 name을 제거 */
Nameval *delitem(Nameval *listp, char *name)
{
    Nameval *p, *prev;
    
    prev = NULL;
    for (p = listp; p != NULL; p = p->next) {
        if (strcmp(name, p->name) == 0) {
            if (prev == NULL)
                listp = p->next;
            else
                prev->next = p->next;
            free(p);
            return listp;
        }
        prev = p;
    }
    eprintf("delitem: %s not in list", name);
    return NULL;        /* can't get here */
}


/* copy: 리스트 복사 */
Nameval *copy(Nameval *src)
{
    Nameval *copyp;
    Nameval *prev;
    Nameval *p;
    
    prev = NULL;
    for ( ; src != NULL; src = src->next) {
        p = newitem(src->name, src->value);
        if (prev == NULL)
            copyp = p;
        else
            prev->next = p;
        prev = p;
    }
    
    return copyp;
}


/* merge: 리스트 합치기 */
Nameval *merge(Nameval *a, Nameval *b)
{
    Nameval *p;
    
    if (a == NULL)
        return b;
    
    for (p = a; p->next != NULL; p = p->next)
        ;
    p->next = b;
    return a;
}


/* split: 리스트 분리하기 */
Nameval *split(Nameval *listp, const char *name)
{
    Nameval *p, *prev, *other;
    
    other = NULL;
    prev = NULL;
    for (p = listp; p != NULL; p = p->next) {
        if (0 == strcmp(p->name, name)) {
            other = p;
            
            if (NULL == prev)
                listp = NULL;
            else
                prev->next = NULL;
            return other;
        }
        prev = p;
    }
    
    return other;
}


/* insert_before: 찾은 원소 앞(전)에 추가하기 */
Nameval *insert_before(Nameval *listp, Nameval *newp, const char *name)
{
    Nameval *p, *prev;
    
    prev = NULL;
    for (p = listp; p != NULL; p = p->next) {
        if (0 == strcmp(p->name, name)) {
            p = addfront(p, newp);
            if (prev == NULL)
                listp = p;
            else
                prev->next = p;
            return listp;
        }
        prev = p;
    }
    return NULL;
}


/* insert_after: 찾은 원소 뒤에 추가하기 */
Nameval *insert_after(Nameval *listp, Nameval *newp, const char *name)
{
    Nameval *p, *prev;
    
    prev = NULL;
    for (p = listp; p != NULL; p = p->next) {
        if (0 == strcmp(p->name, name)) {
            p->next = addfront(p->next, newp);
            return listp;
        }
        prev = p;
    }
    return NULL;
}


/* reverse: 원소의 순서를 거꾸로하기 */
Nameval *reverse_for(Nameval *listp)
{
    Nameval *prev, *temp;
    
    prev = NULL;
    for ( ; listp != NULL; listp = temp) {
        temp = listp->next;
        listp->next = prev;
        prev = listp;
    }
    return prev;
}


/* reverse: 원소의 순서를 거꾸로하기(재귀적 방법) */
Nameval *reverse(Nameval *listp)
{
    Nameval *temp = listp->next;
    Nameval *head = NULL;
    if (temp == NULL)
        return listp;
    
    head = reverse(listp->next);    
    temp->next = listp;
    listp->next = NULL;
    return head;
}
