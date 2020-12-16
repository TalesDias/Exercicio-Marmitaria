#include <stdlib.h>
#include "ArrayList.h"

ArrayList* criarLista(size_t size_elem){
    ArrayList* lista = malloc(sizeof(ArrayList));
    lista->size_elem = size_elem;
    lista->array = malloc(size_elem * INITIAL_SIZE);
    lista->size = INITIAL_SIZE;
    lista->topo = 0;

    return lista;
}

int inserir (ArrayList* lista, void* elem){
    if(lista->topo == (lista->size)){
        int res = dobrarTamanho(lista);
        if (res != 0) return 1;
    }

    ((void**) lista->array)[lista->topo++] = elem;

    return 0;
}

int remover (ArrayList* lista, void* elem, int (*comparator)(void*, void*)){
    int index = encontrarIndex(lista, elem, comparator);
    if (index == -1){
        return 1;
    }

    for(int i = index; i < lista->topo; i++){
        ((void**)lista->array)[i] = ((void**)lista->array)[i+1];
    }

    lista->topo--;

    return 0;
}

int alterar (ArrayList* lista, void* velhoElem, void* novoElem, int (*comparator)(void*, void*)){
    int index = encontrarIndex(lista, velhoElem, comparator);
    if (index == -1){
        return 1;
    }

    ((void**)lista->array)[index] = novoElem;

    return 0;
}

void* consultar (ArrayList* lista, int index){
    if (index > lista->topo) return NULL;
    return ((void**)lista->array)[index];
}

int encontrarIndex (ArrayList* lista, void* elem, int (*comparator)(void*, void*)){
    if (lista->topo == 0) return -1;

    for (int i = 0; i < lista->topo; ++i) {
        if(!comparator(((void**)lista->array)[i], elem)) {
            return i;
        }
    }

    return -1;
}

int dobrarTamanho(ArrayList* lista){
    lista->size *= 2;
    lista->array = realloc(lista->array, lista->size * lista->size_elem);

    return 0;
}

int freeAll(ArrayList* lista){
    free(lista->array);
    return 0;
}
