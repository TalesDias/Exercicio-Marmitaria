#ifndef _MARMITARIA_
#define _MARMITARIA_
#define MAX_DESCRICAO 50

#include "ArrayList.h"


typedef struct {
    int codigoMarmita;
    int quantidade;
} Venda;

typedef struct {
    int codigo;
    char descricao[MAX_DESCRICAO];
    double preco;
    double custo;
    int estoque;
} Marmita;

void menu();
void imprimir_marmita(Marmita marmita);
void cadastrar(ArrayList* marmitas);
void atualizar(ArrayList* marmitas);
void excluir(ArrayList* marmitas);
void vender(ArrayList* marmitas, ArrayList* vendas);
void fechar_caixa(ArrayList* marmitas, ArrayList* vendas);

#endif