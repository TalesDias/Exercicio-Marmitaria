#ifndef MARMITARIA_LOCALSTORAGE_H
#define MARMITARIA_LOCALSTORAGE_H
#include "ArrayList.h"

ArrayList* carregar(char* arquivo, void* (*comparator)(char*), size_t tamanho);

void salvar(char* arquivo, ArrayList* dados, void (*escrever)(void*, char*), char persistir);

#endif //MARMITARIA_LOCALSTORAGE_H
