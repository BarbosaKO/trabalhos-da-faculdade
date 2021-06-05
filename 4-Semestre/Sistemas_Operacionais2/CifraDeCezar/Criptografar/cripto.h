#ifndef CRIPTO_H_INCLUDED
#define CRIPTO_H_INCLUDED
char msg[999];

int GuardarMsgNoVetor(){
    FILE *arq;
    int i=0;
    arq = fopen("..\\texto.txt","r+");
    if(arq == NULL)
        printf("Erro ao abrir o arquivo!\n");
    rewind(arq);
    while(!feof(arq)){
        msg[i] = fgetc(arq);
        i++;
    }
    msg[i-1] = '\0';
    fclose(arq);
    return i;
}
void Criptografar(int chave,int Nt){
    int i;
    for(i=0; i<Nt; i++){
        if(chave>0){    //******************************** CHAVE POSITIVA *********************
            if(msg[i]>64 && msg[i]<91){ // CAIXA ALTA
                if((msg[i]+chave)>90){
                    msg[i] = 64+(msg[i]+chave-90);
                }
                else{
                    msg[i]+= chave;
                }
            }
            if(msg[i]>96 && msg[i]<123){ // CAIXA BAIXA
                if((msg[i]+chave)>122){
                    msg[i] = 96+(msg[i]+chave-122);
                }
                else{
                    msg[i]+= chave;
                }
            }
        }
        else{   //**************************** CHAVE NEGATIVA ****************************************
            if(msg[i]>64 && msg[i]<91){ // CAIXA ALTA
                if((msg[i]+chave)<65){
                    msg[i] = 91+(msg[i]+chave-65);
                }
                else{
                    msg[i]+= chave;
                }
            }
            if(msg[i]>96 && msg[i]<123){    // CAIXA BAIXA
                if((msg[i]+chave)<97){
                    msg[i] = 123+(msg[i]+chave-97);
                }
                else{
                    msg[i]+= chave;
                }
            }
        }
    }
}
void MostrarMsg(int Nt){
    //printf("%d letras no arquivo\n", Nt-1);
    printf("%s\n", msg);
}
void GuardarMsgNoArq(){
    FILE *arq;
    arq = fopen("..\\texto.txt","w");
    if(arq == NULL)
        printf("Erro ao abrir o arquivo!\n");
    fprintf_s(arq,"%s",msg);
    fclose(arq);
}
void AbrirArq(){
    // ABRIR O ARQUIVO REAL, USANDO O SYSTEM
    system("..\\texto.txt");
}

#endif // CRIPTO_H_INCLUDED
