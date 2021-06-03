#include <stdio.h>
void parede(int altura, char c){
    int i;
    for(i = 0; i<altura; i++)
        printf("%c", c);
    printf("\n");
}

void casa(int altura_casa, char c){
    parede(altura_casa-2, c);
    parede(altura_casa-2, c);
    parede(altura_casa, c);
    parede(altura_casa, c);
    parede(altura_casa-2, c);
    parede(altura_casa-2, c);
    printf("\n");
}
