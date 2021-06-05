#include "percurso.h"

/******************************************************************************/
Aresta* createAresta(int vertice1, int vertice2, int pesoAresta)
{
    Aresta* ret = malloc(sizeof(Aresta));
    if (ret == NULL) {
        fprintf(stderr, "Memória esgotada na função %s - (%d)\n", __FUNCTION__, __LINE__);
        exit(0);
    }
    ret->verticeOrigem  = vertice1;
    ret->verticeDestino = vertice2;
    ret->weight         = pesoAresta;
    return ret;
}

/******************************************************************************/
void freeAresta(void* a)
{
   Aresta* ar = a;
   free(ar);
}

/******************************************************************************/
int cmpAresta(void* a1, void* a2)
{
    Aresta* aresta1 = a1;
    Aresta* aresta2 = a2;
    //Lógica para grafo direcionado.
    if (aresta1->verticeOrigem == aresta2->verticeOrigem &&
        aresta1->verticeDestino == aresta2->verticeDestino)
        return 0;
    else
        return 1;
}

/******************************************************************************/
void printAresta(void* a, FILE* pFile)
{
   Aresta* aresta = a;
   printf("(%d, %d, %d)", aresta->verticeOrigem, aresta->verticeDestino, aresta->weight);
}

/******************************************************************************/
void DFS(Grafo* g, int verticeIndex, Deque* listaArestas, int* cor)
{
    (*cor)++;
    setCor(g, verticeIndex, *cor);
    DequeIterator* itArestas = getAdjacentListIT(g, verticeIndex);
    while (DIteratorHasNext(itArestas)) {
        VerticeVizinho* viz = DIteratorNext(itArestas);
        if (getCor(g, viz->indiceVizinho) == 0) {
            Aresta* arestaVisitada = createAresta(verticeIndex, viz->indiceVizinho, viz->pesoAresta);
            pushBackElement(listaArestas, arestaVisitada);
            DFS(g, viz->indiceVizinho, listaArestas, cor);
        }
    }
    destroyDequeIterator(itArestas);
}

/******************************************************************************/
Deque* depthFirstSearch(Grafo* g)
{
    zeraCores(g);
    Deque* edges = createDeque(freeAresta, cmpAresta, printAresta);
    int cor = 0;
    for (int i = 0; i < getNumVertices(g); i++) {
        if (getCor(g, i) == 0) {
            DFS(g, i, edges,&cor);
        }
    }
    return edges;
}

/******************************************************************************/
Deque* breadthFirstSearch(Grafo* g)
{
    zeraCores(g);
    Deque* edges = createDeque(freeAresta, cmpAresta, printAresta);
    Deque* fila  = createDeque(freeNumber, cmpNumber, printNumber);
    int cor = 1;
    for (int i = 0; i < getNumVertices(g); i++) {
        if (getCor(g, i) == 0) {
            setCor(g, i, cor++);
            pushBackElement(fila, createNumber(i));
            while (!isEmptyDeque(fila)) {
                Number *n = popFrontElement(fila);
                DequeIterator* itArestas = getAdjacentListIT(g, n->value);
                while (DIteratorHasNext(itArestas)) {
                    VerticeVizinho* viz = DIteratorNext(itArestas);
                    if (getCor(g, viz->indiceVizinho) == 0) {
                        setCor(g, viz->indiceVizinho, cor++);
                        pushBackElement(fila, createNumber(viz->indiceVizinho));
                        Aresta* arestaVisitada = createAresta(n->value, viz->indiceVizinho, viz->pesoAresta);
                        pushBackElement(edges, arestaVisitada);
                    }
                }
                destroyDequeIterator(itArestas);
                freeNumber(n);
            }
        }
    }
    destroyDeque(fila, true);
    return edges;
}


/******************************************************************************/
Deque* iterativeDepthFirstSearch(Grafo* g)
{

}
