#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;
struct Nameval {
    char *name;
    int value;
};

struct NVtab {
    int nval;           /* 현재 원소의 개수 */
    int max;            /* 현재 할당된 공간의 크기 */
    Nameval *nameval;   /* 이름-값 쌍의 배열 */
} nvtab;

enum { NVINIT = 1, NVGROW = 2 };


/* addname: 새 이름(name)과 값(value)을 nvtab에 추가 */
int addname(Nameval newname)
{
    Nameval *nvp;
    int i;
    
    if (NULL == nvtab.nameval)
    {
        /* 처음 호출되었을 경우 */
        nvtab.nameval = (Nameval *) malloc(NVINIT * sizeof(Nameval));
        if (NULL == nvtab.nameval)
            return -1;
            
        nvtab.max = NVINIT;
        nvtab.nval = 0;
    }
    else if (nvtab.nval >= nvtab.max)
    {
        /* 크기를 늘려야 할 경우 */
        nvp = (Nameval *) realloc(nvtab.nameval,
                        (NVGROW * nvtab.max) * sizeof(Nameval));
        if (NULL == nvp)
            return -1;
        
        nvtab.max *= NVGROW;
        nvtab.nameval = nvp;
    }
    
    for (i = 0; i < nvtab.nval; i++)
    {
        if (nvtab.nameval[i].name == NULL)
            break;
    }
    
    nvtab.nameval[nvtab.nval] = newname;
    return nvtab.nval++;
}


/* delname: nvtab에서 첫 번째로 일치하는 원소를 제거 */
int delname(char *name)
{
    int i;
    
    for (i = 0; i < nvtab.nval; i++)
    {
        // if (0 == strcmp(nvtab.nameval[i].name, name))
        // {
        //     memmove(nvtab.nameval + i, nvtab.nameval + i + 1,
        //         (nvtab.nval - (i + 1)) * sizeof(Nameval));
        //     nvtab.nval--;
        //     return 1;
        // }
        
        if (NULL != nvtab.nameval[i].name &&
            0 == strcmp(nvtab.nameval[i].name, name))
        {
            nvtab.nameval[i].name = NULL;
            nvtab.nameval[i].value = 0;
            nvtab.nval--;
            return 1;
        }
    }
    return 0;
}


void print_nameval()
{
    int i;
    for (i = 0; i < nvtab.max; i++)
    {
        if (0 == i)
            printf(" ");
        else
            printf(" -> ");
            
        if (nvtab.nameval[i].name == NULL)
        {
            printf("*NULL*");
        }
        else
        {
            printf("[%s: %d]", nvtab.nameval[i].name, nvtab.nameval[i].value);
        }
    }
    printf("\n\n");
}


int main(int argc, char *argv[])
{
    Nameval nameval;
    
    nameval.name = "wonury";
    nameval.value = 1;
    addname(nameval);
    
    nameval.name = "jerry";
    nameval.value = 2;
    addname(nameval);
    
    nameval.name = "jakson";
    nameval.value = 3;
    addname(nameval);
    
    nameval.name = "bond";
    nameval.value = 4;
    addname(nameval);
    
    nameval.name = "yang";
    nameval.value = 5;
    addname(nameval);
    
    print_nameval();
    
    delname("bond");
    
    print_nameval();
    
    return 0;
}