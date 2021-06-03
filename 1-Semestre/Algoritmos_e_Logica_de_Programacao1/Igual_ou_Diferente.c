#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
Faça um programa que leia 3 números inteiros e imprima um (e apenas um) dos seguintes números:
1 (Se todos os números são iguais)
2 (Se todos os números são diferentes)
3 (Se apenas dois números são iguais)

Entrada: Consiste de 3 números inteiros
Saída: Consiste de um número indicando uma das 3 situações de igualdade entre os valores de entrada conforme demonstrado na descrição
*/

int main() {
    int x,y,z;
    scanf("%d \n %d \n %d",&x,&y,&z);
    if((x==y)&&(x==z)&&(z==y)){
        printf("1");
    }
    else if((x==y)||(x==z)||(z==y)){
        printf("3");
    }
    else{
        printf("2");
    }
	return 0;
}