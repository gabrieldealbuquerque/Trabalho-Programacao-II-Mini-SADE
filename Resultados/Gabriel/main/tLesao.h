#ifndef _TLESAO_H_
#define _TLESAO_H_

#include <stdio.h>

// Definição do tipo de dado tMedico
typedef struct tLesao tLesao;

tLesao* criaLesao();

void lerLesao();

void printLesao();

void escreveBinLesao();

void lerBinLesao();

char* obtemRotuloLesao();

void defineRotuloLesao();

int obtemIdLesao();

void defineIdLesao();

char* obtemDiagnosticoLesao();

char* obtemRegiaoLesao();

int obtemTamanhoLesao();

char* obtemCirurgiaLesao();

char* obtemCrioterapiaLesao();

void desalocaLesao();

#endif
