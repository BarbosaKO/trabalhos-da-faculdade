#include <stdio.h>
#include <stdlib.h>
#define MAX 21
int main(){
    char *p[3];
    int i,j;
    printf("Digite tres palavras!\n");
    for(i=0; i<3; i++){
        printf("%dº palavra:\n", i+1);
        p[i] = (char *)malloc(MAX*sizeof(char));
        gets(p[i]);
    }
    printf("Suas palavras foram:\n");
    for(i=0; i<3; i++){
        printf("%s\n", p[i]);
        free(p[i]);
    }

    return 0;
}
