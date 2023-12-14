#ifndef _TRELATORIO_H_
#define _TRELATORIO_H_

#include <stdbool.h>

typedef struct tRelatorio tRelatorio;

tRelatorio* criaRelatorio(int pelomenosum, int mediaIdade, int qtdFeminino,
                            int qtdMasculino, int qtdOutros, int tamanhoMedio,
                            int nLesoes, int nCirurgias, int nCrioterapias);

void desalocaRelatorioGenerico(void*);

void desalocaRelatorio(tRelatorio*);

void imprimeNaTelaRelatorio(void* r);

void imprimeEmArquivoRelatorio(void* r, char* path);

int obtemPelomenosum(tRelatorio *relatorio);
int obtemMediaIdade(tRelatorio *relatorio);
int obtemQtdFeminino(tRelatorio *relatorio);
int obtemQtdMasculino(tRelatorio *relatorio);
int obtemQtdOUTROS(tRelatorio *relatorio);
int obtemTamanhoMedioLesoes(tRelatorio *relatorio);
int obtemNLesoes(tRelatorio *relatorio);
int obtemNCirurgias(tRelatorio *relatorio);
int obtemNCrioterapias(tRelatorio *relatorio);

#endif