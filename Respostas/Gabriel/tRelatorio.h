#ifndef _TRELATORIO_H_
#define _TRELATORIO_H_

#include <stdbool.h>

typedef struct tRelatorio tRelatorio;

tRelatorio* criaRelatorio(int pelomenosum, int mediaIdade, int qtdFeminino,
                            int qtdMasculino, int qtdOutros, int tamanhoMedio,
                            int nLesoes, int nCirurgias, int nCrioterapias);

void desalocaRelatorioGenerico(void*);

void desalocaRelatorio(tRelatorio*);

void imprimeNaTelaRelatorio(tRelatorio*);

void imprimeEmArquivoRelatorio(tRelatorio*);

#endif