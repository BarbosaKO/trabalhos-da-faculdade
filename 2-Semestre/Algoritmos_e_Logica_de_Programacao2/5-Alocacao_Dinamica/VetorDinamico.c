#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p;
    int i;
    p = (int *)malloc(5 * sizeof(int));

    for(i=0; i<5; i++)
        *(p+i) = i+1;

    for(i=0; i<5; i++)
        printf("%d\n", *p+i);
    free(p);
    return 0;
}
