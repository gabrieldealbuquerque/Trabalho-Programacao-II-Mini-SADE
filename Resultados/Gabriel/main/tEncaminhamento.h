#ifndef _TENCAMINHAMENTO_H_
#define _TENCAMINHAMENTO_H_

typedef struct tEncaminhamento tEncaminhamento;

tEncaminhamento* criaEncaminhamento(char* nomePaciente, char* cpf, char* nomeMedico, char* CRM, char* data);

tEncaminhamento* CRIAAAaEncaminhamento();

void desalocaEncaminhamento(void* e);

void imprimeNaTelaEncaminhamento(void* e);

void imprimeEmArquivoEncaminhamento(void* e, char* path);

void ler_encaminhamento_de_binario(tEncaminhamento *encaminhamento, FILE *arquivo);

void salvar_encaminhamento_em_binario(tEncaminhamento *encaminhamento, FILE *arquivo);

#endif