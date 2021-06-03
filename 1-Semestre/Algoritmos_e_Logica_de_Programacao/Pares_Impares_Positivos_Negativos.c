#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Leia um valor inteiro N. Depois, imprima uma mensagem dizendo que se este valor for ímpar, par, positivo, negativo ou nulo.
A mensagem deve estar em letras maiúsculas.

    Entrada:    Um número N.
                Considere que o maior inteiro que você poderá receber é 10^12 (10 elevado a 12).
    
    Saída:  Uma frase, informando se o número é POSITIVO PAR, POSITIVO IMPAR, NEGATIVO PAR, NEGATIVO
        IMPAR ou NULO.
            Seguido de uma quebra de linha.
*/

int main() {
    long int x;
    scanf("%li",&x);
    
    if(x != 0){
        if(x > 0 && x % 2 == 0){
            printf("POSITIVO PAR\n");
        }
        else if(x > 0 && x % 2 != 0){
            printf("POSITIVO IMPAR\n");
        }
        else if(x < 0 && x % 2 == 0){
            printf("NEGATIVO PAR\n");
        }
        else if(x < 0 && x % 2 != 0){
            printf("NEGATIVO IMPAR\n");
        }
        
    }
    
    
    else{
        printf("NULO\n");
    }
	return 0;
}