#ifndef PERCURSO_H_INCLUDED
#define PERCURSO_H_INCLUDED
#include "grafo.h"

struct _aresta {
  int verticeOrigem;
  int verticeDestino;
  int weight;
};
typedef struct _aresta Aresta;


Aresta* createAresta(int vertice1, int vertice2, int pesoAresta);
void freeAresta(void* a);
int cmpAresta(void* a1, void* a2);
void printAresta(void* a, FILE* pFile);

void DFS(Grafo* g, int verticeIndex, Deque* listaArestas, int* cor);
Deque* depthFirstSearch(Grafo* g);
Deque* breadthFirstSearch(Grafo* g);
Deque* iterativeDepthFirstSearch(Grafo* g);
#endif // PERCURSO_H_INCLUDED
