#ifndef _TBIOPSIA_H_
#define _TBIOPSIA_H_

#include "tLesao.h"

typedef struct tBiopsia tBiopsia;

tBiopsia* criaBiopsia();

void atribuiValoresBiopsia(tBiopsia* biopsia, char* nome, char* cpf, int qtdLesoes, tLesao** lesoes, 
                        char* nomeMedico, char* CRM, char* data);

void desalocaBiopsia(void* bi);

void imprimeNaTelaBiopsia(void* bi);

void imprimeEmArquivoBiopsia(void* bi, char *path);

void ler_biopsia_de_binario(tBiopsia* biopsia, FILE* arquivo);

void salvar_biopsia_em_binario(tBiopsia* biopsia, FILE* arquivo);

#endif