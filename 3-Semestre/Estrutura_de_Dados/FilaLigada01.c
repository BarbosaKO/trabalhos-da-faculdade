#include <stdio.h>
#include <stdlib.h>

struct _NoFila{
    int valor;
    struct _NoFila *Proximo;
};
typedef struct _NoFila NoFila;

NoFila *Fila = NULL;

void AddNo(int x){
    if(Fila==NULL){
        Fila = malloc(sizeof(NoFila));
        Fila->valor = x;
        Fila->Proximo = NULL;
    }else{
        NoFila *Aux = Fila;
        while(Aux->Proximo!=NULL)
            Aux = Aux->Proximo;
        NoFila *Novo = malloc(sizeof(NoFila));
        Novo->valor = x;
        Novo->Proximo = NULL;
        Aux->Proximo = Novo;
    }
}

void RetirarNo(){
    if(Fila!=NULL){
        NoFila *Aux = Fila;
        Fila = Fila->Proximo;
        free(Aux);
    }else{
        free(Fila);
        printf("Fila inteira removida!");
    }
}

void MostrarFila(){
    NoFila *Aux = Fila;
    while(Aux!=NULL){
        printf("%d ", Aux->valor);
        Aux = Aux->Proximo;
    }
    printf("\n");
}

int main(){
    AddNo(3);
    AddNo(8);
    AddNo(12);
    MostrarFila();
    RetirarNo();
    MostrarFila();
    RetirarNo();
    RetirarNo();
    RetirarNo();

    return 0;
}
