#ifndef _TPESSOA_H_
#define _TPESSOA_H_

#include <stdbool.h>

typedef struct tPessoa tPessoa;

tPessoa* criaPessoa();
void lerPessoa(tPessoa* p);
void printPessoa(tPessoa* p);
void printNomeDataNascPessoa();
void escreveBinPessoa();
void lerBinPessoa();
bool comparaCPFPessoa(tPessoa* p, const char* cpf);
char* obtemCPFPessoa(tPessoa* p);
char* obtemNomePessoa(tPessoa* p);
char* obtemDataPessoa(tPessoa* p);
int calculaIdadePessoa(tPessoa* p);
bool comparaGeneroPessoa(tPessoa* p, const char* genero);
void desalocaPessoa(tPessoa* p);

#endif