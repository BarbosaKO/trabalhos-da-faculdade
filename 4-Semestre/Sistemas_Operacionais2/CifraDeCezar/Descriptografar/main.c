#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "descripto.h"
int main()
{
    setlocale(LC_ALL,"");
    int chave;

    int Nt = GuardarMsgNoVetor();
    printf("Dê a chave cifradora:\n");
    scanf("%d", &chave);
    Descriptografar(chave,Nt);
    MostrarMsg(Nt);
    GuardarMsgNoArq();
    AbrirArq();
    return 0;
}
