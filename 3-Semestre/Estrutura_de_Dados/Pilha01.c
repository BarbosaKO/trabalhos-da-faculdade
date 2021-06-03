#include <stdio.h>
#include <stdlib.h>

int main(){
    int *v;
    int i,j,topo_pilha = 0,opcao,valor;

    while(1){
        printf("1 - Empilhar novo item na pilha!\n2 - Desempilhar!\n3 - Mostrar pilha!\n4 - Sair\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                if(topo_pilha!=6){
                    printf("Digite o valor a ser empilhado:\n");
                    scanf("%d", &valor);
                    topo_pilha++;
                    if(topo_pilha==1)
                        v = (int *)malloc(topo_pilha*sizeof(int));
                    else
                        v = (int *)realloc(v ,topo_pilha*sizeof(int));
                    *(v+(topo_pilha-1)) = valor;
                }else{
                    printf("Pilha cheia!\n");
                }
                break;
            case 2:
                if(topo_pilha!=0){
                    if(topo_pilha==1){
                        free(v);
                    }
                    else{
                        topo_pilha--;
                        v = (int *)realloc(v ,topo_pilha*sizeof(int));
                    }
                }else{
                    printf("Pilha vazia!\n");
                }
                break;
            case 3:
                if(topo_pilha==0){
                    printf("Pilha vazia!\n");
                }else{
                    printf("Pilha: ");
                    for(i=0; i<topo_pilha;i++)
                        printf("%d ", *(v+i));
                    printf("\n");
                }
                break;
            default :
                exit(1);
        }
    }
    return 0;
}
