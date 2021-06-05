#ifndef ESTUDANTE_H_INCLUDED
#define ESTUDANTE_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>

struct _estudante {
    char* nome;
    char* prontuario;
};
typedef struct _estudante Estudante;

void freeEstudante(void*);
int cmpEstudante(void*, void*);
void printEstudante(void*, FILE* pFile);
Estudante* createEstudante(char* nome, char* prontuario);
void testaEstudante();
#endif // ESTUDANTE_H_INCLUDED
