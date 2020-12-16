#ifndef MARMITARIA_LIST_H
#define MARMITARIA_LIST_H

#include <stddef.h>
#define INITIAL_SIZE 5

typedef struct {
    void* array;
    int size;
    int topo;
    size_t size_elem;
} ArrayList;

ArrayList* criarLista(size_t size_elem);

int inserir (ArrayList* lista, void* elem);

int remover (ArrayList* lista, void* elem, int (*comparator)(void*, void*));

int alterar (ArrayList* lista, void* velhoElem, void* novoElem, int (*comparator)(void*, void*));

void* consultar (ArrayList* lista, int index);

int encontrarIndex (ArrayList* lista, void* elem, int (*comparator)(void*, void*));

int dobrarTamanho(ArrayList* lista);

int freeAll(ArrayList *list);


#endif //MARMITARIA_LIST_H
