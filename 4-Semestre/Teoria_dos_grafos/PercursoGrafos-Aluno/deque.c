#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "deque.h"
/******************************************************************************/
void freeNumber(void* data)
{
    Number* n = data;
    free(n);
}

/******************************************************************************/
int cmpNumber(void* data1, void* data2)
{
     Number* n1 = data1;
     Number* n2 = data2;
    return (n1->value - n2->value);
}

/******************************************************************************/
void printNumber(void* data, FILE* pFile)
{
    Number* n = data;
    fprintf(pFile, "%d", n->value);
}

/******************************************************************************/
Number* createNumber(int value)
{
    Number* ret = malloc(sizeof(Number));
    if (ret == NULL) {
        fprintf(stderr, "Memória esgotada na função %s - (%d)\n", __FUNCTION__, __LINE__);
        exit(0);
    }
    ret->value = value;
    return ret;
}


/******************************************************************************/
DequeElement* createElement(void* data)
{
    DequeElement* ret = malloc(sizeof(DequeElement));
    if (ret == NULL) {
        fprintf(stderr, "Memória esgotada na função %s - (%d)\n", __FUNCTION__, __LINE__);
        exit(0);
    }
    memset(ret, 0, sizeof(DequeElement));
    ret->data = data;
    return ret;
}

/******************************************************************************/
void destroyElement(DequeElement* el)
{
    free(el);
}

/******************************************************************************/
Deque* createDeque(void (*func_free)(void*),
                 int (*func_cmp)(void*, void*),
                 void (*func_print)(void*, FILE* pFile))
{
    Deque* ret = malloc(sizeof(Deque));
    if (ret == NULL) {
        fprintf(stderr, "Memória esgotada na função %s - (%d)\n", __FUNCTION__, __LINE__);
        exit(0);
    }
    memset(ret, 0, sizeof(Deque));
    ret->func_cmp = func_cmp;
    ret->func_free = func_free;
    ret->func_print = func_print;
    return ret;
}

/******************************************************************************/
void destroyDeque(Deque* l, bool destroyData)
{
    DequeElement* curr = l->first;
    while (curr != NULL) {
        DequeElement* prox = curr->next;
        if (destroyData)
            l->func_free(curr->data);
        free(curr);
        curr = prox;
    }
    free(l);
}

/******************************************************************************/
bool contains(Deque* l, void* data)
{
    if (data == NULL)
        return false;

    DequeElement* curr = l->first;
    while (curr != NULL) {
        if (l->func_cmp(curr->data, data) == 0)
            return true;
        else
            curr = curr->next;
    }
    return false;
}

/******************************************************************************/
int dequeCount(Deque* l)
{
    return l->count;
}



/******************************************************************************/
bool removeElement(Deque* l, void* data, bool destroyData)
{
    if (data == NULL)
        return false;

    // A lista está vazia
    DequeElement* curr = l->first;
    if (curr == NULL)
        return false;

    // Estamos removendo o primeiro elemento da lista.
    // Exige atualizar l->first
    if (l->func_cmp(curr->data, data) == 0) {
        if (destroyData)
            l->func_free(curr->data);
        l->first = l->first->next;
        if (l->first != NULL)      // Se houver um segundo elemento, vira primeiro.
            l->first->prev = NULL; // O novo primeiro nó não tem anterior.
        else
            l->last = NULL;        // Se a lista ficou vazia, não tem último
        free(curr);
        l->count--;
        return true;
    }
    else {
        DequeElement* prev = curr;
        curr = curr->next;
        while (curr != NULL) {
            if (l->func_cmp(curr->data, data) == 0) {
                if (destroyData)
                    l->func_free(curr->data);
                prev->next = curr->next;
                if (curr->next != NULL)      // Se houver um próximo elemento, vira primeiro.
                    curr->next->prev = prev; // O seguinte ao removido aponta para o anterior ao removido.
                else
                    l->last = prev;          // Se o último foi removido, prev torna-se o último.
                free(curr);
                l->count--;
                return true;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return false;
    }
}

/******************************************************************************/
void pushFrontElement(Deque* l, void* data)
{
    assert(data != NULL);
    DequeElement* novo = createElement(data);
    novo->next = l->first;
    l->first = novo;
    if (l->count == 0){ // A lista estava vazia
        l->last = novo;
    }
    else {
        novo->next->prev = novo;
    }
    l->count++;

}

/******************************************************************************/
void pushBackElement(Deque* l, void* data)
{
    assert(data != NULL);
    DequeElement* novo = createElement(data);
    novo->prev = l->last;
    l->last = novo;
    if (l->count == 0)  //A lista estava vazia
        l->first = novo;
    else
        novo->prev->next = novo;
    l->count++;
}

/******************************************************************************/
void sortedInsert(Deque* l, void* data)
{
    if(l->first == NULL){
        pushFrontElement(l, data);
    }
    else{
        DequeElement* novo = createElement(data);
        DequeElement* curr = l->first;
        while(curr != NULL){
            if(l->func_cmp(curr->data, data) < 0)
                curr = curr->next;
            else{
                novo->next = curr;
                novo->prev = curr->prev;
                if(curr->prev != NULL)
                    curr->prev->next = novo;
                curr->prev = novo;
                if(novo->prev == NULL)
                    l->first = novo;
                l->count++;
            return;
            }
        }
        l->last->next = novo;
        novo->prev = l->last;
        l->last = novo;
        l->count++;
    }
}

/******************************************************************************/
bool isEmptyDeque(Deque* l){
    return (l->first == NULL);
}

/******************************************************************************/
void* popFrontElement(Deque* l)
{
    assert (l->first != NULL);
    void* data = l->first->data;
    DequeElement* curr = l->first;
    l->first = l->first->next;
    if (l->first != NULL)      // Se houver um segundo elemento, vira primeiro.
        l->first->prev = NULL; // O novo primeiro nó não tem anterior.
    else
        l->last = NULL;        // Se a lista ficou vazia, não tem último
    free(curr);
    l->count--;
    return data;
}

/******************************************************************************/
void* popBackElement(Deque* l)
{
    assert (l->first != NULL);
    void* data = l->last->data;
    DequeElement* curr = l->last;
    l->last = l->last->prev;
    if (l->last != NULL)      // Se houver um elemento anterior, vira último.
        l->last->next = NULL; // O novo último nó não tem próximo.
    else
        l->first = NULL;       // Se a lista ficou vazia, não tem primeiro
    free(curr);
    l->count--;
    return data;
}

/******************************************************************************/
void* frontElement(Deque* l)
{
    assert (l->first != NULL);
    return l->first->data;
}

/******************************************************************************/
void* backElement(Deque* l)
{
    assert (l->first != NULL);
    return l->last->data;
}

/******************************************************************************/
void printDeque(Deque* l, FILE* pFile)
{
    DequeElement* curr = l->first;
    while (curr != NULL) {
        l->func_print(curr->data, pFile);
        fprintf(pFile, ", ");
        curr = curr->next;
    }
}

/******************************************************************************/
DequeIterator *createDequeIterator(Deque* l)
{
    DequeIterator *ret = malloc(sizeof(DequeIterator));
    if (ret == NULL) {
        fprintf(stderr, "Memória esgotada na função %s - (%d)\n", __FUNCTION__, __LINE__);
        exit(0);
    }
    // Zera os bytes do iterator
    memset(ret, 0 , sizeof(DequeIterator));
    ret->l = l;
    // Procura pelo primeiro elemento na lista
    if (l->first != NULL) {
        ret->next = l->first;
        ret->hasNext = true;
    }
    return ret;
}

/******************************************************************************/
DequeIterator *createDequeIteratorAtEnd(Deque* l)
{
    DequeIterator *ret = malloc(sizeof(DequeIterator));
    if (ret == NULL) {
        fprintf(stderr, "Memória esgotada na função %s - (%d)\n", __FUNCTION__, __LINE__);
        exit(0);
    }
    // Zera os bytes do iterator
    memset(ret, 0 , sizeof(DequeIterator));
    ret->l = l;
    ///--------------
    ///IMPLMENTE AQUI
    if (l->last != NULL) {
        ret->prev = l->last;
        ret->hasPrevious = true;
    }
    ///--------------
    return ret;
}

/******************************************************************************/
void destroyDequeIterator(DequeIterator* it)
{
    free(it);
}

/******************************************************************************/
void* DIteratorNext(DequeIterator* it)
{
    assert(it->next !=  NULL);
    //Preenche o corrente e avança para o próximo
    if (it->next != NULL) {
        it->curr = it->next->data;
        //Ajusta o previous
        it->prev = it->next;
        if (it->prev == NULL)
            it->hasPrevious = false;
        else
            it->hasPrevious = true;

        // Agora deixa preparado o próximo elemento
        it->next = it->next->next;
        // Se atingir NULL, então atingiu o fim da lista
        if (it->next == NULL)
            it->hasNext = false;
    }
    else {
        // Se o próximo está em NULL, não há mais elementos
        it->hasNext = false;
        it->curr = NULL;
    }
    return it->curr;
}

/******************************************************************************/
void* DIteratorPrevious(DequeIterator* it)
{
    assert(it->prev != NULL);
    //Preenche o corrente e recua para o anterior
    if (it->prev != NULL) {
        it->curr = it->prev->data;
        //Ajusta o next
        it->next = it->prev;
        if (it->next == NULL)
            it->hasNext = false;
        else
            it->hasNext = true;

        // Agora deixa preparado o elemento anterior
        it->prev = it->prev->prev;
        // Se atingir NULL, então atingiu o início da lista
        if (it->prev == NULL)
            it->hasPrevious = false;
    }
    else {
        // Se o anterior está em NULL, não há mais elementos
        it->hasPrevious = false;
        it->curr = NULL;
    }
    return it->curr;
}

/******************************************************************************/
bool DIteratorHasNext(DequeIterator* it)
{
    return it->hasNext;
}


/******************************************************************************/
bool DIteratorHasPrevious(DequeIterator* it)
{
    return it->hasPrevious;
}
