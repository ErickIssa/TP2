#include <stdio.h>
#include <stdlib.h>
#include "ListaSondas.h"
#include <time.h>

int minhaVariavelGlobal = 1;


int main(){

    clock_t inicio = clock();
    SondaMarte sonda1;
    listaSonda sondasL;
    TCompartimento compartimentoL;
    
    FLVazia_Comp(&compartimentoL);
    iniciaListaSonda(&sondasL);

    for(int i = 0;i < 3;i++){
        insereSonda(&sondasL, inicializaSonda(&sonda1));
    }

    ImprimeListaSondas(&sondasL);
    FILE *arq = NULL;
    arq = fopen("testerocha.txt", "r");
    if(arq == NULL){
        printf("falha leitura");
        exit(0);
    }
    int nRochas; 
    float peso, valor;
    fscanf(arq, "%d", &nRochas);

    for(int i = 0; i<nRochas;i++){
        RochaIndv rocha1;
        fscanf(arq,"%f %f", &peso, &valor);
        iniciaRocha(&rocha1, peso, valor, 0);
        LInsere_Comp(&compartimentoL, rocha1);
    }
    LImprime_Comp(compartimentoL);
    clock_t fim = clock();
    double tempo_decorrido = (double)(fim - inicio);
    printf("Tempo gasto: %f segundos\n", tempo_decorrido);
    printf("\n"); 


    return 0;
}