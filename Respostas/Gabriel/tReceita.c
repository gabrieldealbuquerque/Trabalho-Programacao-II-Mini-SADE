#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tReceita.h"

struct tReceita
{
    char nomePaciente[100];
    eTipoUso tipoUso;
    char nomeMedicamento[MAX_TAM_NOME_MEDICAMENTO];
    char tipoMedicamento[MAX_TAM_TIPO_MEDICAMENTO];
    char instrucoes[MAX_TAM_INSTRUCOES];
    int qntd;
    char nomeMedico[100];
    char CRM[12];
    char dataStr[15];
};

// Function to create a new tReceita
tReceita *criaReceita(char *nomePaciente, eTipoUso tipoUso, char *nomeMedicamento,
                      char *tipoMedicamento, char *instrucoes, int qntd,
                      char *nomeMedico, char *CRM, char *dataStr)
{
    tReceita *novaReceita = (tReceita *)calloc(1, sizeof(tReceita));

    if (novaReceita == NULL)
    {
        fprintf(stderr, "Memory allocation error in criaReceita.\n");
        exit(1);
    }

    // Use strdup to duplicate the strings  
    strcpy(novaReceita->nomePaciente, nomePaciente);
    novaReceita->tipoUso = tipoUso;
    strcpy(novaReceita->nomeMedicamento, nomeMedicamento);
    strcpy(novaReceita->tipoMedicamento, tipoMedicamento);
    strcpy(novaReceita->instrucoes, instrucoes);
    novaReceita->qntd = qntd;
    strcpy(novaReceita->nomeMedico, nomeMedico);
    strcpy(novaReceita->CRM, CRM);
    strcpy(novaReceita->dataStr, dataStr);

    return novaReceita;
}

// Function to deallocate a tReceita
void desalocaReceita(void *dado)
{
    if (dado != NULL)
    {
        tReceita *receita = (tReceita *)dado;
        free(receita);
    }
}

// Rest of the code remains unchanged

// Function to print a tReceita to the console
void imprimeNaTelaReceita(void *dado)
{
    if (dado != NULL)
    {
        tReceita *receita = (tReceita *)dado;
        if (receita == NULL)
        {
            printf("Erro de alocacao na receita dentro do imprimeNaTelaReceita\n");
            exit(1);
        }
        printf("RECEITUARIO\n");
        printf("NOME: %s\n", receita -> nomePaciente);
        printf("\n");
        if (receita -> tipoUso == ORAL)
        {
            printf("USO ORAL\n");
        }
        else if (receita -> tipoUso == TOPICO)
        {
            printf("USO TOPICO\n");
        }
        printf("\n");
        printf("%s\n", receita -> nomeMedicamento);
        printf("%d %s\n", receita -> qntd, receita -> tipoMedicamento);
        printf("\n");
        printf("%s\n", receita -> instrucoes);
        printf("\n");
        printf("%s (%s)\n", receita -> nomeMedico, receita -> CRM);
        printf("%s\n", receita -> dataStr);
    }
}

// Function to print a tReceita to a file
void imprimeEmArquivoReceita(void *dado, char *path)
{
    if (dado != NULL)
    {
        tReceita *receita = (tReceita *)dado;
        char filePath[1500];  // Adjust the size as needed
        sprintf(filePath, "%s/%s", path, NOME_ARQUIVO_RECEITA);
        printf("CAMINHO:%s", filePath);
        FILE *re = fopen(filePath, "a");

        if (re == NULL)
        {
            printf("Erro ao abrir o arquivo %s para escrita.\n", path);
            exit(1);
        }

        // Usando fprintf para escrever no arquivo
        fprintf(re, "RECEITUARIO\n");
        fprintf(re, "NOME: %s\n", receita->nomePaciente);
        fprintf(re, "\n");

        if (receita->tipoUso == ORAL)
        {
            fprintf(re, "USO ORAL\n");
        }
        else if (receita->tipoUso == TOPICO)
        {
            fprintf(re, "USO TOPICO\n");
        }

        fprintf(re, "\n");
        fprintf(re, "%s\n", receita->nomeMedicamento);
        fprintf(re, "%d %s\n", receita->qntd, receita->tipoMedicamento);
        fprintf(re, "\n");
        fprintf(re, "%s\n", receita->instrucoes);
        fprintf(re, "\n");
        fprintf(re, "%s (%s)\n", receita->nomeMedico, receita->CRM);
        fprintf(re, "%s\n", receita->dataStr);

        // Fecha o arquivo
        fclose(re);
    }
}
