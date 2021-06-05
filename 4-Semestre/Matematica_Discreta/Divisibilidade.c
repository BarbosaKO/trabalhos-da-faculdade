	#include<stdio.h>
	#include <stdlib.h>
	#include<math.h>
	#include <locale.h>

	int Divisibilidade(int N, int Result)
	{
	
		if(N<19)
		{
			printf("\n%d não é divisível por 19 :(", Result);
		}	
		else if(N==19)
		{
			printf("\n%d é divisível por 19 :)", Result);
		}
		else if(N>19)
		{
			int aux1 = 0, aux2 = 0;
			aux1= (N%10);
			aux2= (N/10);
			aux2 = aux2 + (2*aux1);
			Divisibilidade(aux2, Result);
		}
		
	}


	int main()
	{

		//Definição do conjuntos de sinais da língua-portuguesa.
		setlocale(LC_ALL, "");

		printf("----------DIVISIBILIDADE POR 19--------------\n\n");

		int N;
		int Result;

		printf("Digite o valor que queira checar a divisibilidade\n");
		scanf("%d", &N);

		Result = N;
			
		if(N<0)
			N = N * (-1);
			
		Divisibilidade(N, Result);

			return 0;
	}


