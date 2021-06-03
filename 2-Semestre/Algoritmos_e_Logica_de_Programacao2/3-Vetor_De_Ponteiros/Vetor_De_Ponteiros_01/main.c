#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#define MAX 3
int main()
{
    int *p[MAX];
    int i,j,col;
    printf("Digite o numero de colunas\n");
    scanf("%d", &col);
    for(i=0; i<MAX; i++){
        p[i] = (int *)calloc(col, sizeof(int));
        if(p[i] == NULL){
            exit(1);
        }
    }
    Show(MAX, col, p);
    *(p[1]+3) = 4;
    printf("\n");
    Show(MAX, col, p);

    return 0;
}
