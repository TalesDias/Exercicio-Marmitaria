#ifndef MARMITARIA_LOCALSTORAGE_H
#define MARMITARIA_LOCALSTORAGE_H
#include "ArrayList.h"

ArrayList* carregar(char* arquivo, void* (*comparator)(char*));

void salvar(char* arquivo, ArrayList* dados, int (*escrever)(void*));

#endif //MARMITARIA_LOCALSTORAGE_H
