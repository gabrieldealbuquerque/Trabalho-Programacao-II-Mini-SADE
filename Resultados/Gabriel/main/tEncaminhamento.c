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
    char CRM[12];
    char data[15];
};

tEncaminhamento* criaEncaminhamento(char* nomePaciente, char* cpf, char* nomeMedico, char* CRM, char* data)
{
    printf("ENCAMINHAMENTO:\n");
    tEncaminhamento* encaminhamento = (tEncaminhamento*)calloc(1, sizeof(tEncaminhamento));
    if (encaminhamento != NULL) {
        strcpy(encaminhamento->nomePaciente, nomePaciente);
        strcpy(encaminhamento->cpf, cpf);

        printf("ESPECIALIDADE ENCAMINHADA: ");
        scanf(" %49[^\n]", encaminhamento->especialidade);

        printf("MOTIVO: ");
        scanf(" %299[^\n]", encaminhamento->motivo); // Note o espaço antes do % para consumir a quebra de linha anterior

        strcpy(encaminhamento->nomeMedico, nomeMedico);
        strcpy(encaminhamento->CRM, CRM);
        strcpy(encaminhamento->data, data);
    }
    return encaminhamento;
}

tEncaminhamento* CRIAAAaEncaminhamento()
{
    tEncaminhamento* encaminhamento = (tEncaminhamento*)malloc(sizeof(tEncaminhamento));
    return encaminhamento;
}

void desalocaEncaminhamento(void* e)
{
    tEncaminhamento* en = (tEncaminhamento*) e;
    free(en);
}

void imprimeNaTelaEncaminhamento(void* e)
{
    tEncaminhamento* encaminhamento = (tEncaminhamento*) e;
    printf("PACIENTE: %s\n", encaminhamento->nomePaciente);
    printf("CPF: %s\n", encaminhamento->cpf);
    printf("\nESPECIALIDADE ENCAMINHADA: %s\n", encaminhamento->especialidade);
    printf("MOTIVO: %s\n", encaminhamento->motivo);
    printf("\n%s(%s)\n", encaminhamento->nomeMedico, encaminhamento -> CRM);

    int dia = 0,mes = 0,ano = 0;
    sscanf(encaminhamento->data, "%d/%d/%d", &dia, &mes, &ano);
    sprintf(encaminhamento->data, "%d/%02d/%d", dia,mes,ano);

    printf("%s\n\n", encaminhamento->data);
}

void imprimeEmArquivoEncaminhamento(void* e, char* path)
{
    tEncaminhamento* encaminhamento = (tEncaminhamento*) e;
    char filePath[1500];  // Adjust the size as needed
    sprintf(filePath, "%s/encaminhamento.txt", path);
    FILE *arquivo = fopen(filePath, "a");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    fprintf(arquivo, "PACIENTE: %s\n", encaminhamento->nomePaciente);
    fprintf(arquivo, "CPF: %s\n", encaminhamento->cpf);
    fprintf(arquivo, "\nESPECIALIDADE ENCAMINHADA: %s\n", encaminhamento->especialidade);
    fprintf(arquivo, "MOTIVO: %s\n", encaminhamento->motivo);
    fprintf(arquivo, "\n%s (%s)\n", encaminhamento->nomeMedico, encaminhamento -> CRM);

    int dia = 0,mes = 0,ano = 0;
    sscanf(encaminhamento->data, "%d/%d/%d", &dia, &mes, &ano);
    sprintf(encaminhamento->data, "%d/%02d/%d", dia,mes,ano);
    fprintf(arquivo, "%s\n\n", encaminhamento->data);

    fclose(arquivo);
}

void salvar_encaminhamento_em_binario(tEncaminhamento *encaminhamento, FILE *arquivo)
{
    fwrite(encaminhamento, sizeof(struct tEncaminhamento), 1, arquivo);
}

// Função para ler um encaminhamento de binário
void ler_encaminhamento_de_binario(tEncaminhamento *encaminhamento, FILE *arquivo)
{
    fread(encaminhamento, sizeof(struct tEncaminhamento), 1, arquivo);
}