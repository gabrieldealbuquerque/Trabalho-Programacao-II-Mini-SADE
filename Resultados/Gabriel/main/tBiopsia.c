#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tBiopsia.h"

struct tBiopsia{
    char nome[100];
    char cpf[20];
    int qtdLesoes; 
    tLesao** lesoes;
    char nomeMedico[100];
    char CRM[20];
    char data[20];
};

tBiopsia* criaBiopsia()
{
    tBiopsia* biopsia = (tBiopsia*)calloc(1, sizeof(tBiopsia));
    return biopsia;
}

void atribuiValoresBiopsia(tBiopsia* biopsia, char* nome, char* cpf, int qtdLesoes, tLesao** lesoes, 
                        char* nomeMedico, char* CRM, char* data)
{
    if (biopsia != NULL)
    {
        strcpy(biopsia -> nome, nome);
        strcpy(biopsia -> cpf, cpf);
        biopsia -> qtdLesoes = qtdLesoes;
        biopsia -> lesoes = lesoes;
        strcpy(biopsia -> nomeMedico, nomeMedico);
        strcpy(biopsia -> CRM, CRM);
        strcpy(biopsia -> data, data);
    }
}
void desalocaBiopsia(void* bi)
{
    if (bi != NULL)
    {
        tBiopsia* b = (tBiopsia*) bi;
        for (int i = 0; i < b -> qtdLesoes; i++)
        {
            if (b -> lesoes[i] != NULL)
                desalocaLesao(b -> lesoes[i]);
        }
        if (b -> lesoes != NULL)
            free(b -> lesoes);
        free(b);
    }
}

void imprimeNaTelaBiopsia(void* bi)
{
    tBiopsia* b = (tBiopsia*) bi;

    printf("PACIENTE: %s\n", b->nome);
    printf("CPF: %s\n\n", b->cpf);
    printf("SOLICITACAO DE BIOPSIA PARA AS LESOES:\n");
    for (int i = 0; i < b -> qtdLesoes; i++)
    {
        if (obtemCirurgiaLesao(b -> lesoes[i]))
        {
            printf("L%d - %s - %s - %dMM\n", obtemIdLesao(b -> lesoes[i]), 
            obtemDiagnosticoLesao(b -> lesoes[i]), obtemRegiaoLesao(b -> lesoes[i]), 
            obtemTamanhoLesao(b -> lesoes[i]));
        }
    }

    printf("\n%s (%s)\n", b->nomeMedico, b->CRM);
    printf("%s\n", b->data);
}

void imprimeEmArquivoBiopsia(void* dado, char *path)
{
    tBiopsia* b = (tBiopsia*) dado;
    char filePath[1500];  // Adjust the size as needed
    strcpy(filePath, path);
    strcat(filePath, "/biopsia.txt");
    FILE *arquivo = fopen(filePath, "a");  // Abre o arquivo em modo de adição (append)

    if (arquivo != NULL) {
        fprintf(arquivo, "PACIENTE: %s\n", b->nome);
        fprintf(arquivo, "CPF: %s\n\n", b->cpf);
        fprintf(arquivo, "SOLICITACAO DE BIOPSIA PARA AS LESOES:\n");

        for (int i = 0; i < b->qtdLesoes; i++)
        {
            if (obtemCirurgiaLesao(b->lesoes[i]))
            {
                fprintf(arquivo, "L%d - %s - %s - %dMM\n", obtemIdLesao(b->lesoes[i]), 
                        obtemDiagnosticoLesao(b->lesoes[i]), obtemRegiaoLesao(b->lesoes[i]), 
                        obtemTamanhoLesao(b->lesoes[i]));
            }
        }
        int dia = 0,mes = 0,ano = 0;
        sscanf(b -> data, "%d/%d/%d", &dia, &mes, &ano);
        sprintf(b -> data, "%d/%02d/%d", dia,mes,ano);
        fprintf(arquivo, "\n%s (%s)\n", b->nomeMedico, b->CRM);
        fprintf(arquivo, "%s\n", b->data);

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
}

void salvar_biopsia_em_binario(tBiopsia* biopsia, FILE* arquivo) {
    fwrite(biopsia, sizeof(tBiopsia), 1, arquivo);

    // Salvar as estruturas tLesao apontadas
    for (int i = 0; i < biopsia->qtdLesoes; i++) {
        escreveBinLesao(biopsia->lesoes[i], arquivo);
    }
}

// Função para ler uma biópsia de binário
void ler_biopsia_de_binario(tBiopsia* biopsia, FILE* arquivo) {
     fread(biopsia, sizeof(tBiopsia), 1, arquivo);

    // Alocar espaço para as estruturas tLesao
    biopsia->lesoes = (tLesao**)malloc(sizeof(tLesao *) * biopsia->qtdLesoes);

    // Ler as estruturas tLesao apontadas
    for (int i = 0; i < biopsia->qtdLesoes; i++) {
        biopsia->lesoes[i] = criaLesao();
        lerBinLesao(biopsia->lesoes[i], arquivo);
    }
}