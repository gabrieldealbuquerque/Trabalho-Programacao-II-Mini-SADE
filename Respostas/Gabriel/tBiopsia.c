#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tLesao.h"
#include "tBiopsia.h"

struct tBiopsia{
    char nome[100];
    char cpf[20];
    char rotulo[3];
    char diagnostico[50];
    char regiao[20];
    int tamanho;
    char nomeMedico[100];
    char CRM[20];
    char data[20];
};

tBiopsia* criaBiopsia(const char* nome, const char* cpf, const char* rotulo, const char* diagnostico, const char* regiao,
                        int tamanho, const char* nomeMedico, const char* CRM, const char* data)
{
    tBiopsia* biopsia = (tBiopsia*) calloc (1, sizeof(tBiopsia));
    strcpy(biopsia->nome, nome);
    strcpy(biopsia->cpf, cpf);
    strcpy(biopsia->rotulo, rotulo);
    strcpy(biopsia->diagnostico, diagnostico);
    strcpy(biopsia->regiao, regiao);
    biopsia->tamanho = tamanho;
    strcpy(biopsia->nomeMedico, nomeMedico);
    strcpy(biopsia->CRM, CRM);
    strcpy(biopsia->data, data);
    return biopsia;
}

void desalocaBiopsia(void* bi)
{
    tBiopsia* b = (tBiopsia*) bi;
    free(b);
}

void imprimeNaTelaBiopsia(void* bi)
{
    tBiopsia* b = (tBiopsia*) bi;

    printf("PACIENTE: %s\n", b->nome);
    printf("CPF: %s\n\n", b->cpf);

    printf("SOLICITACAO DE BIOPSIA PARA AS LESOES:\n");
    printf("%s - %s - %s - %dMM\n", b->rotulo, b->diagnostico, b->regiao, b->tamanho);

    printf("\nDR. %s (%s) (%s)\n", b->nomeMedico, b->CRM, b->CRM);
    printf("%s\n", b->data);
}

void imprimeEmArquivoBiopsia(void* bi, char *path)
{
    tBiopsia* b = (tBiopsia*) bi;

    FILE *arquivo = fopen(path, "a");  // Abre o arquivo em modo de adição (append)

    if (arquivo != NULL) {
        fprintf(arquivo, "PACIENTE: %s\n", b->nome);
        fprintf(arquivo, "CPF: %s\n\n", b->cpf);

        fprintf(arquivo, "SOLICITACAO DE BIOPSIA PARA AS LESOES:\n");
        fprintf(arquivo, "%s - %s - %s - %dMM\n", b->rotulo, b->diagnostico, b->regiao, b->tamanho);

        fprintf(arquivo, "\nDR. %s (%s) (%s)\n", b->nomeMedico, b->CRM, b->CRM);
        fprintf(arquivo, "%s\n", b->data);

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
}