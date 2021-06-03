#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p;
    //p = (int *)malloc(sizeof(int));
    p = (int *)calloc(1, sizeof(int));
    printf("p = %d\n", *p);

    p = (int *)realloc(p, 2 * sizeof(int));
    *p = 77;
    *(p+1) = 44;
    printf("p = %d\n", *p);
    printf("p = %d\n", *(p+1));
    free(p);
    return 0;
}
