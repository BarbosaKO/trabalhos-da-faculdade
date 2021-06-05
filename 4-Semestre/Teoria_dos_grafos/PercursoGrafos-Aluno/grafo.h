#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "deque.h"
/// Representa��o de um v�rtice na lista de v�rtices
struct _vertice {
    int indice;       /// �ndice do v�rtice
    int peso;         /// Peso para o v�rtice, caso seja necess�rio
    int cor;          /// Cor serve para marcar n�s visitados, por exemplo
    Deque* adjacentes; /// Lista de v�rtices adjacentes
};
typedef struct _vertice Vertice;

/// Representa��o dos v�rtices adjacentes na lista de adjac�ncias
/// Junto � guardado o peso da aresta.
struct _verticeVizinho {
    int indiceVizinho;
    int pesoAresta;
};
typedef struct _verticeVizinho VerticeVizinho;

/// Representa��o de um grafo
struct _grafo {
    int numVertices;
    bool direcionado;
    Vertice* arrVertices;
};
typedef struct _grafo Grafo;


void destroyVertice(Vertice* v);
Vertice* createVertice(int indice, int peso);


VerticeVizinho* createVerticeVizinho(int indice, int pesoAresta);
void freeVerticeVizinho(void* v);
int cmpVerticeVizinho(void* v1, void* v2);
void printVerticeVizinho(void* v, FILE* pFile);

Grafo* createGrafo(int vertices, bool direcionado);

void destroyGrafo(Grafo* g, bool destroyData);
void addAdjacent(Grafo* g, int verticeIndex, int adjacentVertice, int edgeWeight);
void delAdjacent(Grafo* g, int verticeIndex, int adjacenteVertice, bool destroyData);
void printGraph(Grafo* g, FILE* pFile);
DequeIterator* getAdjacentListIT(Grafo* g, int verticeIndex);
DequeIterator* getAdjacentListITAtEnd(Grafo* g, int verticeIndex);
int degree(Grafo* g, int verticeIndex);
void zeraCores(Grafo* g);
int getCor(Grafo* g, int index);
void setCor(Grafo* g, int index, int cor);
int getNumVertices(Grafo* g);

#endif // GRAFO_H_INCLUDED
