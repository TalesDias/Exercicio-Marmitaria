#include <stdio.h>
#include "ArrayList.h"
#include "Marmitaria.h"

int main(){
    menu();

    /*
    teste a = {.abc = "aaaaaaa", .num = 120};
    teste b = {.abc = "baaaaaa", .num = 1};
    teste c = {.abc = "caaaaaa", .num = 2};
    teste d = {.abc = "daaaaaa", .num = 3};
    teste e = {.abc = "eaaaaaa", .num = 4};
    teste f = {.abc = "faaaaaa", .num = 5};
    teste g = {.abc = "gaaaaaa", .num = 6};
    teste h = {.abc = "haaaaaa", .num = 7};
    teste i = {.abc = "iaaaaaa", .num = 8};
    teste j = {.abc = "jaaaaaa", .num = 9};
    teste k = {.abc = "kaaaaaa", .num = 11};


    ArrayList* arr = criarLista(sizeof(teste));

    printf("\n\n-----------Parte A-----------\n");
    printf("lista vazia: %d\n",encontrarIndex(arr, &a, comparar));
    inserir(arr, &a);
    inserir(arr, &b);
    inserir(arr, &c);
    printf("pos a: %d\n",encontrarIndex(arr, &a, comparar));
    printf("pos e: %d\n", encontrarIndex(arr, &e, comparar));
    printArr(arr);

    printf("\n\n-----------Parte B-----------\n");
    inserir(arr, &d);
    inserir(arr, &e);
    inserir(arr, &f);
    inserir(arr, &g);
    printf("pos a: %d\n", encontrarIndex(arr, &a, comparar));
    printf("pos e: %d\n", encontrarIndex(arr, &e, comparar));
    printArr(arr);

    printf("\n\n-----------Parte C-----------\n");
    printf("consultar %c\n", ((teste*)consultar(arr, 0))->abc);
    printf("remover a: %d\n", remover(arr, &a, comparar));
    printf("remover a: %d\n", remover(arr, &a, comparar));
    printf("remover j: %d\n", remover(arr, &j, comparar));
    printf("consultar %c\n", ((teste*)consultar(arr, 0))->abc);
    printArr(arr);

    printf("\n\n-----------Parte D-----------\n");
    inserir(arr, &a);
    inserir(arr, &h);
    inserir(arr, &i);
    printf("pos a: %d\n", encontrarIndex(arr, &a, compararMarmita));
    printf("pos e: %d\n", encontrarIndex(arr, &e, comparar));
    printArr(arr);

    printf("\n\n-----------Parte E-----------\n");
    alterar(arr, &a, &k, comparar);
    alterar(arr, &b, &k, comparar);
    alterar(arr, &c, &k, comparar);
    printf("pos k: %d\n", encontrarIndex(arr, &k, comparar));
    printArr(arr);

    freeAll(arr);
    */
    return 0;
}
