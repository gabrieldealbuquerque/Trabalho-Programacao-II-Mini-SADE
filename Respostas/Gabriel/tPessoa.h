#ifndef _TPESSOA_H_
#define _TPESSOA_H_

#include <stdbool.h>

typedef struct tPessoa tPessoa;

tPessoa* criaPessoa();

void lerPessoa();

void printPessoa();

void printNomeDataNascPessoa();

void escreveBinPessoa();

void lerBinPessoa();

bool comparaCPFPessoa();

char* obtemCPFPessoa();

char* obtemNomePessoa();

int calculaIdadePessoa();

bool comparaGeneroPessoa();

bool autenticaLogin();

void desalocaPessoa();

#endif