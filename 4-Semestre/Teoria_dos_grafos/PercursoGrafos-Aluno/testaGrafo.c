#include "testaGrafo.h"
#include "percurso.h"
/******************************************************************************/
void testaGrafo()
{
    Grafo* g = createGrafo(9, false);
    printGraph(g, stdout);
    addAdjacent(g, 0, 4, 1);
    addAdjacent(g, 0, 5, 1);
    addAdjacent(g, 0, 6, 1);
    addAdjacent(g, 0, 8, 1);

    addAdjacent(g, 1, 6, 1);

    addAdjacent(g, 2, 7, 1);

    addAdjacent(g, 3, 7, 1);

    addAdjacent(g, 4, 0, 1);
    addAdjacent(g, 4, 8, 1);

    addAdjacent(g, 5, 0, 1);
    addAdjacent(g, 5, 8, 1);

    addAdjacent(g, 6, 0, 1);
    addAdjacent(g, 6, 1, 1);

    addAdjacent(g, 7, 2, 1);
    addAdjacent(g, 7, 3, 1);

    addAdjacent(g, 8, 0, 1);
    addAdjacent(g, 8, 4, 1);
    addAdjacent(g, 8, 5, 1);

    printf("Realizando percurso em profundidade\n");
    Deque* listaArestas = depthFirstSearch(g);
    printDeque(listaArestas, stdout);
    printf("\n");
    destroyDeque(listaArestas, true);
    printGraph(g, stdout);

    printf("Realizando percurso em largura\n");
    listaArestas = breadthFirstSearch(g);
    printDeque(listaArestas, stdout);
    printf("\n");
    destroyDeque(listaArestas, true);
    printGraph(g, stdout);

    destroyGrafo(g, true);
}

/******************************************************************************/
void testaGrafo2()
{
    Grafo* g = createGrafo(10, false);
    printGraph(g, stdout);

    addAdjacent(g, 0, 2, 1);
    addAdjacent(g, 0, 1, 1);
    addAdjacent(g, 0, 5, 1);

    addAdjacent(g, 1, 0, 1);
    addAdjacent(g, 1, 3, 1);
    addAdjacent(g, 1, 4, 1);

    addAdjacent(g, 7, 8, 1);
    addAdjacent(g, 7, 9, 1);

    addAdjacent(g, 2, 0, 1);
    addAdjacent(g, 2, 5, 1);

    addAdjacent(g, 3, 1, 1);
    addAdjacent(g, 3, 5, 1);
    addAdjacent(g, 3, 6, 1);

    addAdjacent(g, 4, 1, 1);
    addAdjacent(g, 4, 6, 1);

    addAdjacent(g, 8, 7, 1);

    addAdjacent(g, 9, 7, 1);

    addAdjacent(g, 5, 2, 1);
    addAdjacent(g, 5, 0, 1);
    addAdjacent(g, 5, 3, 1);

    addAdjacent(g, 6, 3, 1);
    addAdjacent(g, 6, 4, 1);

    printf("Realizando percurso em profundidade\n");
    Deque* listaArestas = depthFirstSearch(g);
    printDeque(listaArestas, stdout);
    printf("\n");
    destroyDeque(listaArestas, true);
    printGraph(g, stdout);

    printf("Realizando percurso em largura\n");
    listaArestas = breadthFirstSearch(g);
    printDeque(listaArestas, stdout);
    printf("\n");
    destroyDeque(listaArestas, true);
    printGraph(g, stdout);

    destroyGrafo(g, true);
}
