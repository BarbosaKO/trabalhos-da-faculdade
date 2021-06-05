#include "grafo.h"
#include <assert.h>
/******************************************************************************/
VerticeVizinho* createVerticeVizinho(int indice, int pesoAresta)
{
    VerticeVizinho* ret = malloc(sizeof(VerticeVizinho));
    if (ret == NULL) {
        fprintf(stderr, "Memória esgotada na função %s - (%d)\n", __FUNCTION__, __LINE__);
        exit(0);
    }
    ret->indiceVizinho = indice;
    ret->pesoAresta = pesoAresta;
    return ret;
}

/******************************************************************************/
void freeVerticeVizinho(void* v)
{
    VerticeVizinho* viz = (VerticeVizinho*) v;
    free(viz);
}

/******************************************************************************/
int cmpVerticeVizinho(void* v1, void* v2)
{
    VerticeVizinho* viz1 = (VerticeVizinho*) v1;
    VerticeVizinho* viz2 = (VerticeVizinho*) v2;
    return (viz1->indiceVizinho - viz2->indiceVizinho);
}

/******************************************************************************/
void printVerticeVizinho(void* v, FILE* pFile)
{
    VerticeVizinho* viz = v;
    printf("(%d, %d)", viz->indiceVizinho, viz->pesoAresta);
}


/******************************************************************************/
void destroyVertice(Vertice* v)
{
    free(v);
}

/******************************************************************************/
Vertice* createVertice(int indice, int peso)
{
    Vertice* ret = malloc(sizeof(Vertice));
    if (ret == NULL) {
        fprintf(stderr, "Memória esgotada na função %s - (%d)\n", __FUNCTION__, __LINE__);
        exit(0);
    }
    ret->indice = indice;
    ret->peso = peso;
    ret->cor = 0;
    return ret;
}

/******************************************************************************/
Grafo* createGrafo(int vertices, bool direcionado)
{
    Grafo* ret = malloc(sizeof(Grafo));
    if (ret == NULL) {
        fprintf(stderr, "Memória esgotada na função %s - (%d)\n", __FUNCTION__, __LINE__);
        exit(0);
    }
    ret->numVertices = vertices;
    ret->direcionado = direcionado;
    ret->arrVertices = malloc(sizeof(Vertice)* vertices);
    if (ret->arrVertices == NULL) {
        fprintf(stderr, "Memória esgotada na função %s - (%d)\n", __FUNCTION__, __LINE__);
        exit(0);
    }
    for (int i = 0; i < vertices; i++) {
        ret->arrVertices[i].cor    = 0;
        ret->arrVertices[i].peso   = 0;
        ret->arrVertices[i].indice = i;
        ret->arrVertices[i].adjacentes = createDeque(freeVerticeVizinho, cmpVerticeVizinho, printVerticeVizinho);
    }
    return ret;
}

/******************************************************************************/
void destroyGrafo(Grafo* g, bool destroyData)
{
    for (int i = 0; i < g->numVertices; i++) {
         destroyDeque(g->arrVertices[i].adjacentes, destroyData);
    }
    free(g->arrVertices);
    free(g);
}

/******************************************************************************/
void addAdjacent(Grafo* g, int verticeIndex, int adjacentVertice, int edgeWeight)
{
    assert(verticeIndex >= 0 && adjacentVertice >= 0);
    assert(verticeIndex < g->numVertices);
    assert(adjacentVertice < g->numVertices);
    VerticeVizinho* viz = createVerticeVizinho(adjacentVertice, edgeWeight);
    pushBackElement(g->arrVertices[verticeIndex].adjacentes, viz);
}

/******************************************************************************/
void delAdjacent(Grafo* g, int verticeIndex, int adjacenteVertice, bool destroyData)
{
   VerticeVizinho* viz = createVerticeVizinho(adjacenteVertice, 0);
   bool ret = removeElement(g->arrVertices[verticeIndex].adjacentes, viz, destroyData);
}


/******************************************************************************/
void printGraph(Grafo* g, FILE* pFile)
{
    fprintf(pFile, "-----------------\n");
    fprintf(pFile, "Quantidade de vértices = %d\n", g->numVertices);
    for (int i =0; i < g->numVertices; i++) {
        printf("Vértice [%3d] = Cor %3d --> ", i, g->arrVertices[i].cor);
        printDeque(g->arrVertices[i].adjacentes, pFile);
        printf("\n");
    }
    fprintf(pFile, "-----------------\n");
}

/******************************************************************************/
DequeIterator* getAdjacentListIT(Grafo* g, int verticeIndex)
{
    return createDequeIterator(g->arrVertices[verticeIndex].adjacentes);
}

/******************************************************************************/
DequeIterator* getAdjacentListITAtEnd(Grafo* g, int verticeIndex)
{
    return createDequeIteratorAtEnd(g->arrVertices[verticeIndex].adjacentes);
}

/******************************************************************************/
int degree(Grafo* g, int verticeIndex)
{
    return g->arrVertices[verticeIndex].adjacentes->count;
}

/******************************************************************************/
void zeraCores(Grafo* g)
{
    for (int i = 0; i < g->numVertices; i++)
        g->arrVertices[i].cor = 0;
}

/******************************************************************************/
int getCor(Grafo* g, int index)
{
    return g->arrVertices[index].cor;
}

/******************************************************************************/
void setCor(Grafo* g, int index, int cor)
{
    g->arrVertices[index].cor = cor;
}

/******************************************************************************/
int getNumVertices(Grafo* g)
{
    return g->numVertices;
}
