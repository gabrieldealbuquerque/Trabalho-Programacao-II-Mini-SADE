#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tEncaminhamento.h"

struct tEncaminhamento{
    char nomePaciente[100];
    char cpf[20];
    char especialidade[50];
    char motivo[300];
    char nomeMedico[100];
    char CRM[30];
    char data[30];
};

tEncaminhamento* criaEncaminhamento(char* nomePaciente, char* cpf, char* nomeMedico, char* CRM, char* data)
{
    tEncaminhamento* encaminhamento = (tEncaminhamento*)malloc(sizeof(tEncaminhamento));
    if (encaminhamento != NULL) {
        strcpy(encaminhamento->nomePaciente, nomePaciente);
        strcpy(encaminhamento->cpf, cpf);

        printf("Digite a Especialidade: ");
        scanf("%49s", encaminhamento->especialidade);

        printf("Digite o Motivo: ");
        scanf(" %299[^\n]", encaminhamento->motivo); // Note o espaço antes do % para consumir a quebra de linha anterior

        strcpy(encaminhamento->nomeMedico, nomeMedico);
        strcpy(encaminhamento->CRM, CRM);
        strcpy(encaminhamento->data, data);
    }
    return encaminhamento;
}

void desalocaEncaminhamento(void* e)
{

}

void imprimeNaTelaEncaminhamento(void* e)
{

}

void imprimeEmArquivoEncaminhamento(void* e, char* path)
{

}