#ifndef _TPESSOA_H_
#define _TPESSOA_H_

#include <stdbool.h>

typedef struct tPessoa tPessoa;

tPessoa* criaPessoa();
void lerPessoa(tPessoa* p);
void printPessoa(tPessoa* p);
void printNomeDataNascPessoa();
void escreveBinPessoa(tPessoa *pessoa, FILE *arquivo);
bool comparaCPFPessoa(tPessoa* p, const char* cpf);
char* obtemCPFPessoa(tPessoa* p);
char* obtemNomePessoa(tPessoa* p);
char* obtemDataPessoa(tPessoa* p);
int calculaIdadePessoa(tPessoa* p);
int comparaGeneroPessoa(tPessoa* p);
void desalocaPessoa(tPessoa* p);
void escreveBinPessoa(tPessoa *pessoa, FILE *arquivo);
tPessoa* lerBinPessoa(FILE *arquivo);
void atribuiNome(tPessoa* pessoa, const char* nome);

#endif