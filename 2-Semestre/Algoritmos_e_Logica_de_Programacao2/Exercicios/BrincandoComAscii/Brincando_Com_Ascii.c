#include <stdio.h>
#include <stdlib.h>

int Mostra_Mapa(int *pY, int *pX){
	int i,j;

	int tamy = 30;
	int tamx = 100;
	char mapa[tamy][tamx];

	char cmd;

	//zera o vetor
	for(i = 0; i<=tamy-1;i++){
		for(j=0;j<=tamx-1;j++){
			mapa[i][j] = ' ';
		}
	}

	//personagem
	mapa[*pY][*pX] = 'O';

	//Carrega o mapa
	for(i = 0; i<=tamy-1;i++){
		for(j=0;j<=tamx-1;j++){
			printf("%c", mapa[i][j]);
			if(j==tamx-1)
				printf("\n");
		}
	}
	scanf(" %c", &cmd);
	printf("%c\n", cmd);
	if(cmd == 'w'){
		*pY = *pY-1;
	}
	else if(cmd == 's'){
		*pY = *pY+1;
	}
	else if(cmd == 'a'){
		*pX = *pX-1;
	}
	else if(cmd == 'd'){
		*pX = *pX+1;
	}
	else{
		system("clear");
		exit(0);
	}
	
}

void main(){
	
	int vdd = 1;
	int y = 0;
	int x = 30;

	while(vdd == 1){
		Mostra_Mapa(&y,&x);
		system("clear");
	}

}