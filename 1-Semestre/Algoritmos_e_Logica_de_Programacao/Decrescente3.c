#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Faça um programa que leia 3 números inteiros e os imprima em ordem decrescente.
    Desafio: tente utilizar apenas 4 comandos if.

    Entrada:    Consiste de 3 números inteiros.

    Saída:  Consiste dos 3 números de entrada ordenados do maior para o menor.
*/

int main(int argc, char *argv[]) {
	int a,b,c, aux;
	scanf("%i%i%i",&a,&b,&c);
	if(a>b)
	{
		aux = a;
		a = b;
		b = aux;
	}
	if(b<=c)
	{
		printf("%i\n%i\n%i\n",c,b,a);
	}
	else
	{
		if(a<=c)
		{
			printf("%i\n%i\n%i\n",b,c,a);
		}
		else
		{
			printf("%i\n%i\n%i\n",b,a,c);
		}
	}
			
	return 0;
}