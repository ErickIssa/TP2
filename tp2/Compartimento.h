#ifndef COMPARTIMENTO_H
#define COMPARTIMENTO_H

#include "Rocha.h"

typedef struct CelulaC* ApontadorC;

typedef struct CelulaC
{
    RochaIndv *ItemR;
    ApontadorC pProx;
} CelulaComp;

typedef struct 
{
    ApontadorC pPrimeiro;
    ApontadorC pUltimo;
} TCompartimento;

void FLVazia_Comp(TCompartimento* comp);
int LInsere_Comp(TCompartimento* comp, RochaIndv rocha);
void LImprime_Comp(TCompartimento comp);
int LEhVazia_Comp(TCompartimento* comp);

#endif