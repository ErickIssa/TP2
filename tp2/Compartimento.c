#include "Compartimento.h"
#include <stdio.h>
#include <stdlib.h>

void FLVazia_Comp(TCompartimento* comp) {
    comp->pPrimeiro = (ApontadorC) malloc(sizeof(TCompartimento));
    comp->pUltimo = comp->pPrimeiro;
    comp->pPrimeiro->pProx = NULL;
}

int LInsere_Comp(TCompartimento* comp, RochaIndv rocha) {
    comp->pUltimo->pProx = (ApontadorC) malloc(sizeof(CelulaComp));
    comp->pUltimo = comp->pUltimo->pProx;
    comp->pUltimo->ItemR = rocha;
    comp->pUltimo->pProx = NULL;
    return 0;
}

void LImprime_Comp(TCompartimento comp) {
    ApontadorC pAux = NULL;
    pAux = comp.pPrimeiro->pProx;

    while (pAux != NULL) {
        printf("Peso: %f\n", pAux->ItemR->pesoRocha);
        printf("Valor: %f\n", pAux->ItemR->valorRocha);
        pAux = pAux->pProx;
    }
}

int LEhVazia_Comp(TCompartimento* comp) {
    return comp->pPrimeiro == comp->pUltimo;
}
