#ifndef _TBIOPSIA_H_
#define _TBIOPSIA_H_

typedef struct tBiopsia tBiopsia;

tBiopsia* criaBiopsia(const char* nome, const char* cpf, const char* rotulo, const char* diagnostico, const char* regiao,
                        int tamanho, const char* nomeMedico, const char* CRM, const char* data);

void desalocaBiopsia(void* bi);

void imprimeNaTelaBiopsia(void* bi);

void imprimeEmArquivoBiopsia(void* bi, char *path);

#endif