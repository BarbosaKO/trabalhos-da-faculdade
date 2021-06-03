#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
Faça um programa que leia três notas (valores reais) de um aluno, calcule sua média aritmética e imprima uma mensagem dizendo se o aluno foi aprovado, reprovado ou deverá fazer prova final. O critério de aprovação é o seguinte: 
    Aprovado (média >= 7);
    Reprovado (média < 3);
    Prova final ( 3 <= média < 7).

    Entrada: 03 números reais separados por um final de linha.
    Saída: 
        Uma mensagem que pode ser: 

                aprovado
                reprovado
                prova final

        Dependendo da situação do aluno.
        A saída deve terminar com uma quebra de linha.
*/

int main() {
	int x,y,z,nf;
	
	scanf("%d %d %d", &x, &y, &z);
	nf = (x+y+z)/ 3;
	if(nf>=7){
		printf("aprovado");
	}
	else if(nf>=3){
		printf("prova final");
	}
	else{
		printf("reprovado");
	}
	return 0;
}