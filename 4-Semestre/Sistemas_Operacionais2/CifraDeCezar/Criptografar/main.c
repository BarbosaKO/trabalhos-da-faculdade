#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "cripto.h"
int main()
{
    setlocale(LC_ALL,"");
    int chave;

    int Nt = GuardarMsgNoVetor();
    //MostrarMsg(Nt);
    printf("Dê a chave cifradora:\n");
    scanf("%d", &chave);
    Criptografar(chave,Nt);
    MostrarMsg(Nt);
    GuardarMsgNoArq();
    AbrirArq();
    return 0;
}
