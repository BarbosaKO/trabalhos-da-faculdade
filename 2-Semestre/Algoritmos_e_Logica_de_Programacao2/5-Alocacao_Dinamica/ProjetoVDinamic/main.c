#include <stdio.h>
#include <stdlib.h>
#include "MCRF.h"

int main()
{
    int i;
    int *p;
//*********** MALLOC *****************
//    p = Memory_Alloc(3);
//    for(i=0;i<3;i++)
//        scanf("%d", p+i);
//    for(i=0;i<3;i++)
//        printf("%d\n", *(p+i));
//    Free_Memory(p);

//************ CALLOC *****************
    p = Zero_Initialize(3);
    printf("Memoria alocada inicialmente com zeros\n");
    MostraVetor(p);

    for(i=0;i<3;i++)
        scanf("%d", p+i);
    MostraVetor(p);
  //  Free_Memory(p);

//************* REALLOC ****************

    if(!Realocate_Memory(p,4))
        exit(0);
    printf("Memoria Realocada\n");
    for(i=0;i<4;i++)
        printf("%d\n", *(p+i));
    printf("Digite o valor do novo espaco na memoria\n");
    scanf("%d", p+3);
    printf("Memoria Realocada com o Novo Valor\n");
    for(i=0;i<4;i++)
        printf("%d\n", *(p+i));


//    Trocar(p);
//    printf("Valores trocados\n");
//    MostraVetor(p);

    Free_Memory(p);
    return 0;
}
