#ifndef MCRF_H_INCLUDED
#define MCRF_H_INCLUDED
#endif // MCRF_H_INCLUDED

int *Memory_Alloc(int tam){
    int *v;
    v = (int *)malloc(tam*sizeof(int));
    if(v==NULL)
        return 0;
    return v;
}
void MostraVetor(int *v){
    int i;
    for(i=0;i<3;i++)
        printf("%d\n", *(v+i));
}

int *Zero_Initialize(int tam){
    int *v;
    v = (int *)calloc(tam, sizeof(int));
    if(v==NULL)
        return 0;
    return v;
}

int Realocate_Memory(int *p, int tam){
    p = (int *)realloc(p, tam*sizeof(int));
    if(p==NULL)
        return 0;
    return 1;
}

int Trocar(int *v){
    *(v+0) = 9;
    *(v+2) = 8;
    return 1;
}

int Free_Memory(int *p){
    free(p);
}
