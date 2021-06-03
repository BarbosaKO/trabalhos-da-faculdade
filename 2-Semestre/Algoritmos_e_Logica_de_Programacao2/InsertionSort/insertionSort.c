#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int v[] = {32,26,14,1,79,6};
    int i,j,chave, len = 6;

    for(j = 1; j<len; j++){
        chave = v[j];
        i = j-1;
        while(i>=0 && v[i]>chave){
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = chave;
    }
    for(i=0; i<len; i++){
        printf("%d ", v[i]);
    }
    return 0;
}
