#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p;
    p = (int *)calloc(1, sizeof(int));
    printf("p = %d\n", *p);
    free(p);
    return 0;
}
