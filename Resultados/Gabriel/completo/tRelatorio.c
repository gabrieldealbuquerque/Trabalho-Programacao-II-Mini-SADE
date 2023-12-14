#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tRelatorio.h"

struct tRelatorio{
    int pelomenosum;
    int mediaIdade;
    int qtdFeminino;
    int qtdMasculino;
    int qtdOUTROS;
    int tamanhoMedioLesoes;
    int nLesoes;
    int nCirurgias;
    int nCrioterapias;
};

tRelatorio* criaRelatorio(int pelomenosum, int mediaIdade, int qtdFeminino,
                            int qtdMasculino, int qtdOutros, int tamanhoMedio,
                            int nLesoes, int nCirurgias, int nCrioterapias)
{
    tRelatorio* relatorio = (tRelatorio*) calloc (1, sizeof(tRelatorio));
    relatorio -> pelomenosum = pelomenosum;
    relatorio -> mediaIdade = mediaIdade;
    relatorio -> qtdFeminino = qtdFeminino;
    relatorio -> qtdMasculino = qtdMasculino;
    relatorio -> qtdOUTROS = qtdOutros;
    relatorio -> tamanhoMedioLesoes = tamanhoMedio;
    relatorio -> nLesoes = nLesoes;
    relatorio -> nCirurgias = nCirurgias;
    relatorio -> nCrioterapias = nCrioterapias;

    return relatorio;
}

void desalocaRelatorioGenerico(void* r)
{
    tRelatorio* relatorio = (tRelatorio*) r;
    free(relatorio);
}

void desalocaRelatorio(tRelatorio* r)
{
    free(r);
}

void imprimeNaTelaRelatorio(void* r)
{
    tRelatorio* relatorio = (tRelatorio*) r;
    printf("NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n", relatorio->pelomenosum);
    printf("IDADE MEDIA: %d\n", relatorio->mediaIdade);
    printf("DISTRIBUICAO POR GENERO:\n");
    printf("- FEMININO: %d\n", relatorio->qtdFeminino);
    printf("- MASCULINO: %d\n", relatorio->qtdMasculino);
    printf("- OUTROS: %d\n", relatorio->qtdOUTROS);
    printf("TAMANHO MEDIO DAS LESOES: %d\n", relatorio->tamanhoMedioLesoes);
    printf("NUMERO TOTAL DE LESOES: %d\n", relatorio->nLesoes);
    printf("NUMERO TOTAL DE CIRURGIAS: %d\n", relatorio->nCirurgias);
    printf("NUMERO TOTAL DE CRIOTERAPIA: %d\n", relatorio->nCrioterapias);
}

void imprimeEmArquivoRelatorio(void* r, char* path)
{
    tRelatorio* relatorio = (tRelatorio*) r;
    char filePath[1500];  // Adjust the size as needed
    sprintf(filePath, "%s/relatorio_geral.txt", path);
    FILE *arquivo = fopen(filePath, "a");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    fprintf(arquivo, "NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n", relatorio->pelomenosum);
    fprintf(arquivo, "IDADE MEDIA: %d\n", relatorio->mediaIdade);
    fprintf(arquivo, "DISTRIBUICAO POR GENERO:\n");
    fprintf(arquivo, "- FEMININO: %d\n", relatorio->qtdFeminino);
    fprintf(arquivo, "- MASCULINO: %d\n", relatorio->qtdMasculino);
    fprintf(arquivo, "- OUTROS: %d\n", relatorio->qtdOUTROS);
    fprintf(arquivo, "TAMANHO MEDIO DAS LESOES: %d\n", relatorio->tamanhoMedioLesoes);
    fprintf(arquivo, "NUMERO TOTAL DE LESOES: %d\n", relatorio->nLesoes);
    fprintf(arquivo, "NUMERO TOTAL DE CIRURGIAS: %d\n", relatorio->nCirurgias);
    fprintf(arquivo, "NUMERO TOTAL DE CRIOTERAPIA: %d\n", relatorio->nCrioterapias);

    fclose(arquivo);
}

int obtemPelomenosum(tRelatorio *relatorio) {
    return relatorio->pelomenosum;
}

int obtemMediaIdade(tRelatorio *relatorio) {
    return relatorio->mediaIdade;
}

int obtemQtdFeminino(tRelatorio *relatorio) {
    return relatorio->qtdFeminino;
}

int obtemQtdMasculino(tRelatorio *relatorio) {
    return relatorio->qtdMasculino;
}

int obtemQtdOUTROS(tRelatorio *relatorio) {
    return relatorio->qtdOUTROS;
}

int obtemTamanhoMedioLesoes(tRelatorio *relatorio) {
    return relatorio->tamanhoMedioLesoes;
}

int obtemNLesoes(tRelatorio *relatorio) {
    return relatorio->nLesoes;
}

int obtemNCirurgias(tRelatorio *relatorio) {
    return relatorio->nCirurgias;
}

int obtemNCrioterapias(tRelatorio *relatorio) {
    return relatorio->nCrioterapias;
}