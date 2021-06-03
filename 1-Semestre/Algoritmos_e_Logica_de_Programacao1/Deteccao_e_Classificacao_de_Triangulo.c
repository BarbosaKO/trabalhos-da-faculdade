#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
        Sabe-se que para que seja possível a formação de um triângulo, é necessário que a soma de dois 
    lados quaisquer seja maior que o terceiro lado. Sabe-se também que um triângulo escaleno possui 
    todos os lados diferentes, um triângulo isósceles possui apenas dois lados iguais e um triângulo 
    equilátero possui todos os lados iguais. Escreva um programa que permita verificar se três 
    valores fornecidos pelo utilizador podem formar ou não um triângulo e, em caso positivo, que 
    triângulo seria esse. Caso não forme um triângulo, deve ser impresso o caractere ‘-‘ (hífen).
    Caso forme, deve ser impresso seu tipo em letras maiúsculas e sem acentuação. A tabela abaixo 
    traz exemplos de entrada e saída esperadas.
*/

int main() {
    double l1, l2, l3;

      scanf ("%lf%lf%lf", &l1,&l2,&l3);
      
      if (l1 + l2 > l3 && l1 + l3 > l2 && l2 + l3 > l1)
         {
          if (l1 == l2 && l2 == l3 && l3 == l1){
             printf ("EQUILATERO");
             }
          else if (l1 == l2 || l2 == l3 || l3 == l1){
             printf ("ISOSCELES");
             }
          else if (l1 != l2 && l2 != l3 && l3 != l1){
             printf ("ESCALENO");
             }
         }
      else
          printf ("-");
	return 0;
}