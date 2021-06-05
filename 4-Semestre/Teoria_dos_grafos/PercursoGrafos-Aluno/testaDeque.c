#include "testaDeque.h"
#include "deque.h"
/******************************************************************************/
void testaLista()
{
   //Cria a lista
   Deque* lista = createDeque(&freeNumber, &cmpNumber, &printNumber);

   DequeIterator* it = createDequeIterator(lista);
   printf( "Percorre iterador em lista vazia\n");
   while (DIteratorHasNext(it)) {
        Number* n = (Number*) DIteratorNext(it);
        printf("%d, ", n->value);
   }
   printf("\n");
   destroyDequeIterator(it);

   printf("Imprime lista vazia\n");
   printDeque(lista, stdout);
   printf("\n");

   pushBackElement(lista, createNumber(1));
   Number* n = popBackElement(lista);
   printf("Retirou %d\n", n->value);
   freeNumber(n);

   pushFrontElement(lista, createNumber(1));
   n = popFrontElement(lista);
   printf("Retirou %d\n", n->value);
   freeNumber(n);

   //Preenche a lista com alguns valores
   for (int i = 0; i < 10; i++) {
      Number* n = createNumber(i);
      pushFrontElement(lista, n);
   }

   //Percorre a lista usando iteradores
   it = createDequeIterator(lista);

   printf("Vamos navegar simultaneamente para frente e para trás no iterador\n");
   n = (Number*) DIteratorNext(it);
   printf("%d\n", n->value);
   n = (Number*) DIteratorPrevious(it);
   printf("%d\n", n->value);

   printf("Vai até o fim do iterador\n");
   while (DIteratorHasNext(it)) {
        Number* n = (Number*) DIteratorNext(it);
        printf("%d, ", n->value);
   }
   printf("\n");

   printf("Volta até o começo iterador\n");
   while (DIteratorHasPrevious(it)) {
        Number* n = (Number*) DIteratorPrevious(it);
        printf("%d, ", n->value);
   }
   printf("\n");

   //Vamos procurar um item:
   n = createNumber(0);
   bool existe = contains(lista, n);
   printf("%d %s\n", n->value, (existe?"está presente": "não está presente"));
   n->value = 50;
   existe = contains(lista, n);
   printf("%d %s\n", n->value, (existe?"está presente": "não está presente"));

   //Vamos remover um item:
   n->value = 9;
   existe = removeElement(lista, n, true);
   printf("%d %s\n", n->value, (existe?"estava presente": "não estava presente"));
   n->value = 5;
   existe = removeElement(lista, n, true);
   printf("%d %s\n", n->value, (existe?"estava presente": "não estava presente"));
   n->value = 0;
   existe = removeElement(lista, n, true);
   printf("%d %s\n", n->value, (existe?"estava presente": "não estava presente"));
   n->value = 50;
   existe = removeElement(lista, n, true);
   printf("%d %s\n", n->value, (existe?"estava presente": "não estava presente"));

   printDeque(lista, stdout);
   printf("\n");

   destroyDequeIterator(it);
   it = createDequeIterator(lista);
   printf("Vai até o fim do iterador\n");
   while (DIteratorHasNext(it)) {
        Number* n = (Number*) DIteratorNext(it);
        printf("%d, ", n->value);
   }
   printf("\n");

   printf("Volta até o começo do iterador\n");
   while (DIteratorHasPrevious(it)) {
        Number* n = (Number*) DIteratorPrevious(it);
        printf("%d, ", n->value);
   }
   printf("\n");
   destroyDequeIterator(it);

   printf("Cria iterador no final\n");
   it = createDequeIteratorAtEnd(lista);
   printf("Volta até o começo do iterador\n");
   while (DIteratorHasPrevious(it)) {
        Number* n = (Number*) DIteratorPrevious(it);
        printf("%d, ", n->value);
   }
   printf("\n");
    destroyDequeIterator(it);

   //Total de elementos na lista
   printf("Há %d elementos na lista\n", dequeCount(lista));

   freeNumber(n);
   destroyDequeIterator(it);
   destroyDeque(lista, true);

//*******************************************************************************
//**************************** Sorted List **************************************
//*******************************************************************************
    lista = createDeque(&freeNumber, &cmpNumber, &printNumber);
    sortedInsert(lista, createNumber(5));
    printDeque(lista, stdout);
    printf("\n");
    sortedInsert(lista, createNumber(4));
    printDeque(lista, stdout);
    printf("\n");
    sortedInsert(lista, createNumber(10));
    printDeque(lista, stdout);
    printf("\n");
    sortedInsert(lista, createNumber(6));
    printDeque(lista, stdout);
    printf("\n");
    sortedInsert(lista, createNumber(1));
    printDeque(lista, stdout);
    printf("\n");
    sortedInsert(lista, createNumber(1));
    printDeque(lista, stdout);
    printf("\n");
    sortedInsert(lista, createNumber(6));
    printDeque(lista, stdout);
    printf("\n");

    it = createDequeIterator(lista);
    printf("Vai até o fim do iterador\n");
    while (DIteratorHasNext(it)) {
        Number* n = (Number*) DIteratorNext(it);
        printf("%d, ", n->value);
   }
    printf("\n");

    printf("Volta até o começo do iterador\n");
    while (DIteratorHasPrevious(it)) {
        Number* n = (Number*) DIteratorPrevious(it);
        printf("%d, ", n->value);
   }
    printf("\n");
    destroyDequeIterator(it);
    destroyDeque(lista, true);
}
