#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Marmitaria.h"

void menu(){

    //ArrayList* marmitas = carregar("caminho para o arquivo", ler);


    ArrayList* marmitas = criarLista(sizeof(Marmita));
    ArrayList* vendas = criarLista(sizeof(Venda));



    int opcao, exit = 0;
    do {
        printf("---------------------------------------------------\n");
        printf("------------ SISTEMA MARMITARIAS 2000 -------------\n\n");
        printf("O que deseja fazer?\n\n");
        printf("1. CADASTRAR MARMITA\n");
        printf("2. ALTERAR MARMITA\n");
        printf("3. EXCLUIR MARMITA\n");
        printf("4. VENDER MARMITA\n");
        printf("5. ENCERRAR O DIA\n");
        printf("---------------------------------------------------\n\n");


        scanf("%d", &opcao);
        getchar();//resolve o bug de pular linha

        switch (opcao) {
            case 1: cadastrar(marmitas); break;
            case 2: atualizar(marmitas); break;
            case 3: excluir(marmitas); break;
            case 4: vender(marmitas, vendas); break;
            case 5:
                printf("---------------------------------------------------\n");
                printf("------------ SISTEMA MARMITARIAS 2000 -------------\n\n");
                printf("Tem certeza de que deseja encerrar o dia?\n\n");
                printf("1. CONFIRMAR\n");
                printf("2. CANCELAR\n");
                printf("---------------------------------------------------\n\n");
                scanf("%d", &exit);
                getchar();

                if (!(exit-1)){
                    fechar_caixa(marmitas, vendas);
                    exit = 1;
                }
                else exit = 0;

                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }

    } while(!exit);

    freeAll(marmitas);
    freeAll(vendas);
}


//Funções auxiliares
int ler_descricao(char *desc){
    char ch;
    int i = 0;
    while((ch=getchar())!='\n' && i < MAX_DESCRICAO-1)
    {
        desc[i] = ch;
        i++;
    }
    i++;
    desc[i]='\0';
    return i;
}

int compararMarmita(void* ma, void* mb){
    Marmita a = ((Marmita*) ma)[0];
    Marmita b = ((Marmita*) mb)[0];

    if (a.codigo > b.codigo)  return 1;
    if (a.codigo < b.codigo)  return -1;
    return 0;
}

int compararVenda(void* va, void* vb){
    Venda a = ((Venda*) va)[0];
    Venda b = ((Venda*) vb)[0];

    if (a.codigoMarmita > b.codigoMarmita)  return 1;
    if (a.codigoMarmita < b.codigoMarmita)  return -1;
    return 0;
}

void* ler (char* linha){
    //CRIAR MARMITA COM MALLOC
    //recebe uma linha
    //converte a linha para marmita
    //retorna o endereco
    return NULL;
}

char* escrever(void* elem){
    //converter elem para marmita
    //retornar uma string
    return "";
}


//Funções definidas no arquivo cabeçalho (marmitaria.h)
void imprimir_marmita (Marmita marmita){
    printf("%s: Preco: R$ %.2lf (cod: %d, estoque : %d)\n",
           strtok(marmita.descricao, "\n"), marmita.preco, marmita.codigo, marmita.estoque);
}

void cadastrar(ArrayList* marmitas){

    Marmita marmita;

    printf("---------------------------------------------------\n");
    printf("------------ SISTEMA MARMITARIAS 2000 -------------\n\n");
    printf("Digite os dados da marmita\n\n");
    printf("Codigo da Marmita:\n");
    scanf("%d", &marmita.codigo);
    getchar();

    if (marmita.codigo <= 0) {
        printf("CÓDIGO INVALIDO!!!\n");
        printf("---------------------------------------------------\n\n");
        return;
    }

    printf("Descricao da Marmita:\n");
    if (!ler_descricao(marmita.descricao)) {
        printf("DESCRIÇÃO NÃO PODE SER VAZIA!!!\n");
        printf("---------------------------------------------------\n\n");
        return;
    }

    printf("Preco de Venda:\n");
    scanf("%lf", &marmita.preco);
    printf("Custo de Producao:\n");
    scanf("%lf", &marmita.custo);
    printf("Quantidade em Estoque:\n");
    scanf("%d", &marmita.estoque);

    Marmita* permMarmita = malloc(sizeof(Marmita));
    memcpy(permMarmita, &marmita, sizeof(Marmita));

    if(inserir(marmitas, permMarmita)){
        printf("PROBLEMA DESCONHECIDO, ABORTANDO...\n");
        printf("---------------------------------------------------\n\n");
        return;
    }

    printf("\nMarmita Cadastrada com sucesso!!!\n\n");
    printf("---------------------------------------------------\n\n");
}

void atualizar(ArrayList* marmitas){
    if(marmitas->topo == 0){
        printf("SEM MARMITAS CADASTRADAS!!!\n");
        printf("---------------------------------------------------\n\n");
        return;
    }

    int cod;

    printf("---------------------------------------------------\n");
    printf("------------ SISTEMA MARMITARIAS 2000 -------------\n\n");
    printf("Codigo da Marmita a ser alterada:\n");
    scanf("%d", &cod);
    getchar();

    if (cod <= 0) {
        printf("CÓDIGO INVALIDO!!!\n");
        printf("---------------------------------------------------\n\n");
        return;
    }

    int index = encontrarIndex(marmitas, &((Marmita) {.codigo = cod}), compararMarmita);

    if(index == -1){
        printf("MARMITA NÃO EXISTENTE!!!\n");
        printf("---------------------------------------------------\n\n");
        return;
    }

    Marmita* marmita = (Marmita*)consultar(marmitas, index);
    printf("Digite os novos dados da marmita\n");


    printf("Descricao da Marmita:\n");
    if (!ler_descricao(marmita->descricao)) {
        printf("DESCRIÇÃO NÃO PODE SER VAZIA!!!\n");
        printf("---------------------------------------------------\n\n");
        return;
    }

    printf("Preco de Venda:\n");
    scanf("%lf", &marmita->preco);
    printf("Custo de Producao:\n");
    scanf("%lf", &marmita->custo);
    printf("Quantidade em Estoque:\n");
    scanf("%d", &marmita->estoque);

    printf("\nMarmita Alterada com sucesso!!!\n\n");
    printf("---------------------------------------------------\n\n");
}

void excluir(ArrayList* marmitas){
    if(marmitas->topo == 0){
        printf("SEM MARMITAS CADASTRADAS!!!\n");
        printf("---------------------------------------------------\n\n");
        return;
    }

    int cod;

    printf("---------------------------------------------------\n");
    printf("------------ SISTEMA MARMITARIAS 2000 -------------\n\n");
    printf("Codigo da marmita a ser excluida:\n");
    scanf("%d", &cod);
    if(cod <= 0){
        printf("CÓDIGO INVALIDO!!!\n");
        printf("---------------------------------------------------\n\n");
        return;
    }

    Marmita marmita = {.codigo = cod};
    int index = encontrarIndex(marmitas, &marmita, compararMarmita);

    if(index == -1){
        printf("MARMITA NÃO EXISTENTE!!!\n");
        printf("---------------------------------------------------\n\n");
        return;
    }

    if(remover(marmitas, &marmita, compararMarmita)){
        printf("PROBLEMA DESCONHECIDO, ABORTANDO...\n");
        printf("---------------------------------------------------\n\n");
        return;
    }

    printf("\nMarmita Excluida com sucesso!!!\n\n");
    printf("---------------------------------------------------\n\n");

}

void vender(ArrayList* marmitas, ArrayList* vendas){
    if(marmitas->topo == 0){
        printf("SEM MARMITAS CADASTRADAS!!!\n");
        printf("---------------------------------------------------\n\n");
        return;
    }

    printf("---------------------------------------------------\n");
    printf("------------ SISTEMA MARMITARIAS 2000 -------------\n\n");

    printf("MARMITAS DISPONIVEIS:\n\n");

    for (int i = 0; i < marmitas->topo; ++i) {
        imprimir_marmita(((Marmita*)consultar(marmitas,i))[0]);
        printf("---------------------------------------------------\n");
    }
    printf("Informe o codigo da marmita que deseja a comprar\n");
    int cod;
    scanf("%d", &cod);
    getchar();

    if(cod <= 0){
        printf("CÓDIGO INVALIDO!!!\n");
        printf("---------------------------------------------------\n\n");
        return;
    }

    int index = encontrarIndex(marmitas, &((Marmita) {.codigo = cod}), compararMarmita);

    if(index == -1){
        printf("MARMITA NÃO EXISTENTE!!!\n");
        printf("---------------------------------------------------\n\n");
        return;
    }

    Marmita* marmita = ((Marmita*)consultar(marmitas, index));

    printf("Informe a quantidade que deseja comprar\n");
    int quantidade;
    scanf("%d", &quantidade);
    getchar();

    if(marmita->estoque < quantidade){
        printf("MARMITA SEM ESTOQUE!!!\n");
        printf("---------------------------------------------------\n\n");
        return;
    }

    marmita->estoque -= quantidade;
    Venda* venda = &((Venda){.quantidade = quantidade, .codigoMarmita = cod});

    index = encontrarIndex(vendas, venda, compararVenda);
    if(index == -1){
        Venda* permVenda = malloc(sizeof(Venda));
        memcpy(permVenda, venda, sizeof(Venda));
        inserir(vendas, permVenda);
    }
    else {
        venda = ((Venda*)consultar(vendas, index));
        venda->quantidade += quantidade;
    }

    printf("%s Vendido(a) com Sucesso!!!\n", marmita->descricao);
    printf("Lembre-se de desejar um bom apetite\n");
    printf("---------------------------------------------------\n");
}

void fechar_caixa(ArrayList* marmitas, ArrayList* vendas){
    printf("---------------------------------------------------\n");
    printf("------------ SISTEMA MARMITARIAS 2000 -------------\n\n");
    printf("--------------- FECHAMENTO DE CAIXA ---------------\n\n");

    int tot_vendas = 0;
    double receita = 0.0, custos = 0.0;
    Venda dummy;
    dummy.quantidade = -1;
    Venda populares[3] = {dummy, dummy, dummy};

    for (int i = 0; i < vendas->topo; ++i) {
        Venda venda = ((Venda*)consultar(vendas, i))[0];

        int index = encontrarIndex(marmitas, &((Marmita) {.codigo=venda.codigoMarmita}), compararMarmita);
        if (index < 0) continue; //verificando se a marmita não foi excluida

        Marmita marmita = ((Marmita*) consultar(marmitas, index))[0];

        tot_vendas += venda.quantidade;
        receita += marmita.preco * venda.quantidade;
        custos += marmita.custo * venda.quantidade;

        if (populares[2].quantidade < venda.quantidade){
            if (populares[1].quantidade < venda.quantidade){
                if (populares[0].quantidade < venda.quantidade){
                    populares[2] = populares[1];
                    populares[1] = populares[0];
                    populares[0] = venda;
                }
                else {
                    populares[2] = populares[1];
                    populares[1] = venda;
                }
            }
            else {
                populares[2] = venda;
            }
        }
    }

    printf("Marmitas vendidas hoje: %d\n", tot_vendas);
    printf("Marmitas mais populares\n");

    for (int i = 0; i < 3; ++i) {
        int index = encontrarIndex(marmitas, &((Marmita) {.codigo=populares[i].codigoMarmita}), compararMarmita);
        if (index < 0) continue; //verificando se a marmita não foi excluida
        Marmita marmita = ((Marmita*) consultar(marmitas, index))[0];

        printf("%dº- %s: %d unidades\n",(i+1) , marmita.descricao, populares[i].quantidade);
    }
    printf("\n");

    printf("Faturamento bruto: %.2lf\n", receita);
    printf("Faturamento liquido: %.2lf\n", receita - custos);

    char opcao;
    printf("Deseja ver o estque final? (y/n)\n");
    scanf("%c", &opcao);
    getchar();

    if (opcao == 'n'){
        printf("------- OBRIGADO POR USAR MARMITARIAS 2000 -------\n\n");
        return;
    }

    for(int i = 0; i < marmitas->topo; ++i){
        Marmita marmita = ((Marmita*) consultar(marmitas, i))[0];
        printf("%d: %s\n", marmita.codigo, marmita.descricao);
        printf("%d unidades em estoque\n\n", marmita.estoque);
    }

    printf("------- OBRIGADO POR USAR MARMITARIAS 2000 -------\n\n");
    return;
}
