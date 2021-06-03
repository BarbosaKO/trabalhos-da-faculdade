#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>

/* ################################################################################################################
		Trabalho final de Algebra Linear - parte 1
	Esse código consiste em gerar uma chave cifradora a partir de uma matriz(2x2), e gerar uma matriz decifradora que usaremos como chave. 
Criamos uma mensagem qualquer e o algoritmo criptografa a mensagem. A mensagem só podera ser descriptografada com o segundo programa.
   ################################################################################################################ */

void RemovEspace(char *mensagem){
    int len = strlen(mensagem);
    for(int i = 0, posicao = 0; i < len; i++, posicao++){
        if (mensagem[posicao] == ' ')
            posicao++;
        mensagem[i] = mensagem[posicao];
    }
    len = strlen(mensagem);
    if(len%2==0){
        mensagem[len] = '\0';
        mensagem[len-1] = mensagem[len-2];
    }
}
int mod26(int a){
    int r = abs(a)%26;
    if(a>=0){
        return r;
    }
    else if(a<0 && r != 0){
        return 26-r;
    }else if(a<0 && r==0){
        return 0;
    }
    else{
        exit(1);
    }
}
int reciproco(int DetMod26){
    if(DetMod26 == 1)
        return DetMod26;
    else if(DetMod26 == 3)
        return 9;
    else if(DetMod26 == 5)
        return 21;
    else if(DetMod26 == 7)
        return 15;
    else if(DetMod26 == 9)
        return 3;
    else if(DetMod26 == 11)
        return 19;
    else if(DetMod26 == 15)
        return 7;
    else if(DetMod26 == 17)
        return 23;
    else if(DetMod26 == 19)
        return 11;
    else if(DetMod26 == 21)
        return 5;
    else if(DetMod26 == 23)
        return 17;
    else if(DetMod26 == 25)
        return 25;
    else
        exit(1);
}
void mostrarMatriz(int chave[4]){
    printf("|%d %d|\n|%d %d|\n", chave[0],chave[1],
                                chave[2],chave[3]);

}
//*****************Testar se chave é permitida********************************
int MatrizChaveEhInvertivel(int chave[4]){
    int det = CalcularDet(chave);
    if(det%2==0 || det%13==0)
        return 1;
    else
        return 0;
}
int CalcularDet(int chave[4]){
    int det = (chave[0]*chave[3])-(chave[1]*chave[2]);
    return det;
}

//*******************Calcular matriz chave inversa****************************
void CriarChaveInversa(int chave[4], int *ChaveInv){
    int i;
    int DetMod26 = mod26(CalcularDet(chave));
    DetMod26 = reciproco(DetMod26);
    printf("%d\n",DetMod26);

    ChaveInv[0] = mod26((DetMod26) * (chave[3]));
    ChaveInv[1] = mod26((DetMod26) * (-(chave[1])));
    ChaveInv[2] = mod26((DetMod26) * (-(chave[2])));
    ChaveInv[3] = mod26((DetMod26) * (chave[0]));
}

//***********************Montar Matriz Cifrada************************
void MatrizMsgInN(char *mensagem, int tam, int *msgInN, char alfabeto[26]){
    int i,j;
    for(i = 0; i<tam; i++){
        for(j=0; j<26; j++){
            if(mensagem[i] == alfabeto[j]){
                msgInN[i] = j;
            }
        }
    }
}
void MatrizMsgInL(char *mensagem, int tam, int *msgInNumC, char alfabeto[26]){
    int i,j;
    for(i = 0; i<tam; i++){
        for(j=0; j<26; j++){
            if(msgInNumC[i] == j){
                mensagem[i] = alfabeto[j];
            }
        }
    }
}
int main(){
    char letras[] = {'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'};
    int i,chave[4],chaveInversa[] = {0,0,0,0};
    char mensagem[101];
    int LEN;

    label:
    printf("Vamos criar uma matriz(2x2) para cifrar as mensagens.\n");
    for(i=0; i<4; i++){
        scanf("%d", &chave[i]);
    }
    if(MatrizChaveEhInvertivel(chave) == 1)
        {
            printf("Matriz chave nao permitida...\n");
            goto label;
        }
    CriarChaveInversa(chave,chaveInversa);
    printf("Matriz Cifradora:\n");
    mostrarMatriz(chave);
    printf("Matriz Decifradora:\n");
    mostrarMatriz(chaveInversa);

//*************************** Cifrar Mensagem *********************************
    printf("Escreva sua mensagem:\n");
    fflush(stdin);
    fgets(mensagem, sizeof(mensagem), stdin);
    RemovEspace(mensagem);  // REMOVE OS ESPAÇOS
    LEN = strlen(mensagem);
    int mensInNum[LEN], mensInNumC[LEN];

    MatrizMsgInN(mensagem,LEN,mensInNum,letras); //CRIA A MATRIZ DA MENSAGEM (EM NUMEROS)
    for(i=0;i<LEN;i++)
        printf("%d ", mensInNum[i]);

    //************** FAZ A MULT. ENTRE A MATRIZ CHAVE E A MATRIZ MENSAGEM**************
    printf("\n\nMensagem Cifrada:\n");
    for(int k=0,a=0,b=0,cont=0; k<LEN; k++){
        cont++;
        if(cont == 1)
            a = mensInNum[k];
        if(cont == 2){
            b = mensInNum[k];
            mensInNumC[k-1] = mod26((chave[0]*a) + (chave[1]*b));
            mensInNumC[k] = mod26((chave[2]*a) + (chave[3]*b));
            cont = 0;
        }
    }
    for(i=0;i<LEN;i++)
        printf("%d ", mensInNumC[i]);

    MatrizMsgInL(mensagem,LEN,mensInNumC,letras); //MATRIZ DA MATRIZ CIFRADA (EM LETRAS)
    printf("\n%s", mensagem);

    return 0;
}
