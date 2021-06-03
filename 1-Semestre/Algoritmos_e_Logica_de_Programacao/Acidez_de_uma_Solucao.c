#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Escreva um programa que leia o valor do índice de acidez (pH) de uma solução e informe se ela é ácida, básica ou neutra.

A solução é ácida quando o pH é menor que 7

A solução é básica quando o pH é maior que 7

Caso contrário a solução é neutra

Entrada:    O valor do pH (entre 1.0 e 14.0)

Saída:  
            Caso a solução seja básica, escreva "Basica" na saída
            Caso a solução seja ácida, escreva "Acida" na saída
            Caso a solução seja neutra, escreva "Neutra" na saída
*/

int main() {
    float ph;
    scanf("%f",&ph);
    if ((ph>1.0)&&(ph<14.0))
    {
    if (ph<7)
    {
        printf("Acida");
    }
    else if (ph>7)
    {
        printf("Basica");
    }
    else 
    {
        printf("Neutra");
    }
    }
   
	return 0;
}