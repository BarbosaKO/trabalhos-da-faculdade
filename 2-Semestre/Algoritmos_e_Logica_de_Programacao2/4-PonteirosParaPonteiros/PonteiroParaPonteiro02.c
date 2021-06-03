#include <stdio.h>
#include <stdlib.h>

int main(){
    char **p;
    int i,j,qtd=3, tamanho = 4;
    p = (char **)malloc(qtd*sizeof(char *));
    *(p+0) = (char *)malloc(tamanho*sizeof(char));
    *(p+1) = (char *)malloc(2*sizeof(char));
    *(p+2) = (char *)malloc(5*sizeof(char));
    gets(*(p+0));   fflush(stdin);
    gets(*(p+1));   fflush(stdin);
    gets(*(p+2));   fflush(stdin);

    for(i=0; i<3; i++){
        printf("Palavra: %s\n", *(p+i));
        free(*(p+i));
    }
    free(p);
}
