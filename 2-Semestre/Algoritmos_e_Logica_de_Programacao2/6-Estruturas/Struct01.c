#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia,mes,ano;
}Data;

typedef struct{
    char Nome[81];
    Data DT_Nasc;
}Pessoa;

int main(){
    Pessoa v[3] = {{"Gabriel",{28,10,2000} },{"Emanuele",{12,7,2001}},{"Marcel",{8,4,2000}} };
    int i=0;
    printf("Qual pessoa vc quer ver?\n");
    scanf("%d",&i);

    printf("%s\n%d/%d/%d\n", v[i].Nome, v[i].DT_Nasc.dia,v[i].DT_Nasc.mes,v[i].DT_Nasc.ano);
    printf("\n");

    while(1){
        printf("Qual pessoa vc quer ver?\n");
        scanf("%d",&i);
        printf("%s\n%d/%d/%d\n", v[i].Nome, v[i].DT_Nasc.dia,v[i].DT_Nasc.mes,v[i].DT_Nasc.ano);
        printf("\n");
    }
    return 0;
}
