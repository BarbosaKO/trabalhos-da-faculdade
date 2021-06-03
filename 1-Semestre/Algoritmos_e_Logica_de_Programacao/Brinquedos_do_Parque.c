#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Nos parques de diversão, alguns brinquedos tem idade e altura mínimas para poder andar neles.

O parque Ambrolândia possui 3 brinquedos que possuem essa limitação:

Barca Viking: 1,5m de altura e 12 anos.

Elevator of Death: 1,4m de altura e 14 anos.

Final Killer: 1,7m de altura ou 16 anos. 

Dada a altura e a idade de uma pessoa, faça um programa que identifique quantos brinquedos ele pode andar.

Entrada:    Dois inteiros, F e I, representando a altura (em cm) e a idade, respectivamente.
Saída:  O número de brinquedos que ele pode andar no parque, seguido de uma quebra de linha.
*/

int main() {
    int F,I,p=0;
    scanf("%d %d", &F, &I);
    if((F>=170)||(I>=16)){
        p+=1;
    }
    if((F>=140)&&(I>=14)){
        p+=1;
    }
    if((F>=150)&&(I>=12)){
        p+=1;
    }
    printf("%d\n",p);
	return 0;
}