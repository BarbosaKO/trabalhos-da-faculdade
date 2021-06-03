#include <stdio.h>
#include <stdlib.h>

void Show(int lin,int col,int **p){
    int i,j;
    for(i=0; i<lin; i++){
        for(j=0; j<col; j++){
            printf("%d ", *(p[i]+j) );
        }
        printf("\n");
    }
}
