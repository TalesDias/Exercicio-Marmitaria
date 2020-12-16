#include <stdlib.h>
#include "ArrayList.h"
#include "stdio.h"

ArrayList* carregar(char* arquivo, void* (*ler)(char*), size_t tamanho){
    FILE* arq;
    char linha[100];
    ArrayList*  arr = criarLista(tamanho);

    if ((arq = fopen(arquivo,"r")) == NULL){
        printf("Erro ao Ler o arquivo: %s\n", arquivo);
        exit(1);
    }

    while (fgets(linha, sizeof(linha), arq) != NULL) {
        void* elem = ler(linha);
        inserir(arr, elem);
    }

    return arr;
}

void salvar(char* arquivo, ArrayList* dados, void (*escrever)(void*, char*), char persistir){
    FILE *arq;
    if (persistir!='y') {
         arq = fopen(arquivo, "w");
    }
    else{
        arq = fopen(arquivo,"a");
        fprintf(arq,"\n");
    }
    if (arq == NULL){
        printf("Erro ao Ler o arquivo: %s\n", arquivo);
        exit(1);
    }

    for (int i = 0; i < dados->topo; ++i) {
        char* buffer =  malloc(sizeof(char)*100);
        escrever(consultar(dados, i), buffer);

        if (i+1 == dados->topo){
            fprintf(arq, "%s", buffer);
        }
        else{
            fprintf(arq, "%s\n", buffer);
        }
        free(buffer);
    }

}