#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>

/// Representa��o de um inteiro
struct _number {
    int value;
};
typedef struct _number Number;

void freeNumber(void*);
int cmpNumber(void*, void*);
void printNumber(void*, FILE* pFile);

Number* createNumber(int value);


/// N� de um elemento na lista gen�rica
/// Pode-se armazenar qualquer coisa, basta passar o apontador
/// Que � mantido em data
struct _dequeElement {           /// Lista n�o intrusiva
    void* data;                  /// Apontador gen�rico para os dados
    struct _dequeElement* next;  /// Apontador para o pr�ximo elemento da lista
    struct _dequeElement* prev;  /// Apontador para o elemento anterior da lista
};
typedef struct _dequeElement DequeElement;


/// Trabalhamos com uma lista com n� cabe�a.
/// Mantemos a quantidade de elementos em count
/// E fun��es call back para:
///    Desalocar a mem�ria do dado mantido
///    Comparar um dado com outro: ZERO � igual, mesma sem�ntica de strcmp()
///    Imprimir num arquivo os dados
struct _deque {
    int count;                     /// Total de v�rtices vizinhos
    DequeElement* first;           /// Apontador para o primeiro elemento da lista
    DequeElement* last;            /// Apontador para �ltimo elemento da lista
    void (*func_free)(void*);      /// Fun��o que desaloca n�
    int (*func_cmp)(void*, void*); ///Fun��o que compara elementos
    void (*func_print)(void*, FILE* pFile);
};
typedef struct _deque Deque;

/// Iterador para List
struct _dequeIterator {
    DequeElement *next;
    DequeElement *prev;
    void *curr;
    bool hasNext;
    bool hasPrevious;
    Deque *l;
};
typedef struct _dequeIterator DequeIterator;

DequeElement* createElement(void* data);
void destroyElement(DequeElement* el);
Deque* createDeque(void (*func_free)(void*),
                   int (*func_cmp)(void*, void*),
                   void (*func_print)(void*, FILE* pFile));
void destroyDeque(Deque* l, bool destroyData);
bool contains(Deque* l, void* data);
bool removeElement(Deque* l, void* data, bool destroyData);
void pushFrontElement(Deque* l, void* data);
void pushBackElement(Deque* l, void* data);
void* popFrontElement(Deque* l);
void* popBackElement(Deque* l);
void* frontElement(Deque* l);
void* backElement(Deque* l);
void sortedInsert(Deque* l, void* data);
bool isEmptyDeque(Deque* l);
int dequeCount(Deque* l);
void printDeque(Deque* l, FILE*);

DequeIterator *createDequeIterator(Deque* l);
DequeIterator *createDequeIteratorAtEnd(Deque* l);
void destroyDequeIterator(DequeIterator* it);
void* DIteratorNext(DequeIterator* it);
bool DIteratorHasNext(DequeIterator* it);
void* DIteratorPrevious(DequeIterator* it);
bool DIteratorHasPrevious(DequeIterator* it);

#endif // DEQUE_H_INCLUDED
