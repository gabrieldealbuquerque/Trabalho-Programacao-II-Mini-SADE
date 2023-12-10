#ifndef _TENCAMINHAMENTO_H_
#define _TENCAMINHAMENTO_H_

typedef struct tEncaminhamento tEncaminhamento;

tEncaminhamento* criaEncaminhamento();

void desalocaEncaminhamento(void* e);

void imprimeNaTelaEncaminhamento(void* e);

void imprimeEmArquivoEncaminhamento(void* e, char* path);

#endif