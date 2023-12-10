#ifndef _TSECRETARIO_H_
#define _TSECRETARIO_H_

typedef struct tSecretario tSecretario;

tSecretario* criaSecretario();

void lerSecretario();

void defineIdSecretario(tSecretario* s, int id);

void defineIdLoginSecretario(tSecretario* s, int id);

void printSecretario();

void escreveBinSecretario();

void lerBinSecretario();

char* retornaLoginSecretario(void* secre);

char* retornaSenhaSecretario(void* secre);

char* retornaAcessoSecretario(void *secre);

char* obtemCPFSecretario(void* secre);

void adicionaSecretarioSade(void** s, void* adicionar, int qtdSecretarios);

void desalocaSecretario(void* sec);

#endif