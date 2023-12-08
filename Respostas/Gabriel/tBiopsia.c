#include <stdio.h>
#include <stdlib.h>
#include "tLesao.h"
#include "tBiopsia.h"

struct tBiopsia{
    char nome[100];
    char cpf[20];
    tLesao* lesao;
    char nomeMedico[100];
    char CRM[20];
    char data[20];
};

tBiopsia* criaBiopsia()
{
    tBiopsia* biopsia = (tBiopsia*) calloc (1, sizeof(tBiopsia));
    biopsia -> lesao = criaLesao();
    return biopsia;
}

void desalocaBiopsia(tBiopsia* b)
{
    desalocaLesao(b -> lesao);
    free(b);
}

void imprimeNaTelaBiopsia(tBiopsia* b)
{

}

void imprimeEmArquivoBiopsia(tBiopsia* b)
{

}