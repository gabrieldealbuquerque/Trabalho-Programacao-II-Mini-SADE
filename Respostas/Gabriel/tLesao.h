#ifndef _TLESAO_H_
#define _TLESAO_H_

#include <stdbool.h>
#include <stdio.h>

// Definição do tipo de dado tMedico
typedef struct tLesao tLesao;

tLesao* criaLesao();

void lerLesao(tLesao* l);

void printLesao();

void escreveBinLesao(tLesao* l, FILE* arquivo);

void lerBinLesao(tLesao* l, FILE* arquivo);

char* obtemRotuloLesao(tLesao* l);

void defineRotuloLesao(tLesao* l, const char* rotulo);

tLesao* copiaLesao(tLesao* a);

int obtemIdLesao(tLesao* l);

void defineIdLesao(tLesao* l, int id);

char* obtemDiagnosticoLesao(tLesao* l);

char* obtemRegiaoLesao(tLesao* l);

int obtemTamanhoLesao(tLesao* l);

bool obtemCirurgiaLesao(tLesao* l);

bool obtemCrioterapiaLesao(tLesao* l);

void desalocaLesao(tLesao* l);

#endif
