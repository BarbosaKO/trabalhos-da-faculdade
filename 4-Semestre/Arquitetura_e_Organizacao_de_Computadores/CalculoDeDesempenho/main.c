#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

float TempoCPU(){
    float CI,CPI,TCC,TX;
    printf("Contador de Instrucao:\n");
        scanf("%f", &CI);
    printf("CPI:\n");
        scanf("%f", &CPI);
    if(TipoDeEquacao() == 1){
        printf("Tempo de Ciclo de Clock:\n");
            scanf("%f", &TCC);
        return ( CI*CPI*TCC );
    }else{
        printf("Taxa de Clock:\n");
            scanf("%f", &TX);
        return ( (CI*CPI)/TX );
    }
}

float CI(){
    float CPI,TCC,TX,TCPU;
    printf("Tempo de CPU:\n");
        scanf("%f", &TCPU);
    printf("CPI:\n");
        scanf("%f", &CPI);
    if(TipoDeEquacao() == 1){
        printf("Tempo de Ciclo de Clock:\n");
            scanf("%f", &TCC);
        return ( TCPU/(CPI*TCC) );
    }else{
        printf("Taxa de Clock:\n");
            scanf("%f", &TX);
        return ( (TCPU*TX)/CPI );
    }
}

float CPI(){
    float TCC,TX,TCPU,CI;
    printf("Tempo de CPU:\n");
        scanf("%f", &TCPU);
    printf("Contador de Instruções:\n");
        scanf("%f", &CI);
    if(TipoDeEquacao() == 1){
        printf("Tempo de Ciclo de Clock:\n");
            scanf("%f", &TCC);
        return ( TCPU/(CI*TCC) );
    }else{
        printf("Taxa de Clock:\n");
            scanf("%f", &TX);
        return ( (TCPU*TX)/CI );
    }
}

float TempoCicloClock(){
    float CPI,TCPU,CI;
    printf("Tempo de CPU:\n");
        scanf("%f", &TCPU);
    printf("Contador de Instruções:\n");
        scanf("%f", &CI);
    printf("CPI:\n");
        scanf("%f", &CPI);
    return ( TCPU/(CI*CPI) );
}

float TaxaClock(){
    float CPI,TCPU,CI;
    printf("Tempo de CPU:\n");
        scanf("%f", &TCPU);
    printf("Contador de Instruções:\n");
        scanf("%f", &CI);
    printf("CPI:\n");
        scanf("%f", &CPI);
    return ( (CI*CPI)/TCPU );
}

int TipoDeEquacao(){
    int opcao,K=1;
    while(K==1){
        printf("\nVocê tem:\n1-Tempo de Ciclo de Clock?\n2-Taxa de Clock?\n");
        scanf("%d", &opcao);
        if((opcao==1)||(opcao==2) )
            K=0;
    }
    return opcao;
}

int main(){
    int opcao;
    setlocale(LC_ALL,"");
    float t=5E9;
    printf("        Calculo de Desempenho de CPUs %f\n\n", t);
    while(1){
        printf("    Digite a escolha do que você quer calcular:\n1- Tempo de CPU\n2- Contador de Instruções\n3- CPI\n4- Tempo de Ciclo de Clock\n5- Taxa de Clock\n6- Sair\n    *Obs: Utilize virgúla(,) em vez de Ponto(.)\n\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Tempo de CPU = %f\n", TempoCPU());
                break;
            case 2:
                printf("Contador de Instrução = %f\n", CI());
                break;
            case 3:
                printf("CPI = %f\n", CPI());
                break;
            case 4:
                printf("Tempo de Ciclo de Clock = %f\n", TempoCicloClock());
                break;
            case 5:
                printf("Taxa de Clock = %f\n", TaxaClock());
                break;
            case 6: exit(1); break;
            default: printf("Opcao Invalida!\n\n");
        }
    }
    return 0;
}
