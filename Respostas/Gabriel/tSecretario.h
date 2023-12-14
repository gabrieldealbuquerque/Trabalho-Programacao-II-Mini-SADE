#ifndef _TSECRETARIO_H_
#define _TSECRETARIO_H_

typedef struct tSecretario tSecretario;
#include "tPessoa.h"

tSecretario* criaSecretario();

void lerSecretario();

void defineIdSecretario(tSecretario* s, int id);

void defineIdLoginSecretario(tSecretario* s, int id);

void printSecretario();

char* retornaLoginSecretario(void* secre);

char* retornaSenhaSecretario(void* secre);

char* retornaAcessoSecretario(void *secre);

char* obtemCPFSecretario(void* secre);

size_t tamanhoSecretario(tSecretario* m);

int obtemGeneroSecretario(tSecretario* secretario);

int calculaidadeSecretario(tSecretario* secretario);

tSecretario* criaSecretarioLeitura();

void adicionaSecretarioSade(void** s, void* adicionar, int qtdSecretarios);

void desalocaSecretario(void* sec);

char* obtemNomeSecretario(void* secre);

tPessoa* retornaPessoaSecretario(tSecretario* secretario);

void salvar_secretario_em_binario(tSecretario* secretario, FILE* arquivo);

void ler_secretario_de_binario(tSecretario* secretario, FILE* arquivo);

#endif