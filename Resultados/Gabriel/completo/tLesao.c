#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "tLesao.h"
#include <string.h>

struct tLesao{
    char rotulo[5];
    int id;
    char diagnostico[50];
    char regiao[20];
    int tamanho;
    int cirurgia;
    int crioterapia; 
};

tLesao* criaLesao()
{
    tLesao* lesao = calloc (1, sizeof(tLesao));
    return lesao;
}

void lerLesao(tLesao* l)
{
    printf("DIAGNOSTICO CLINICO:\n");
    scanf(" %49[^\n]", l->diagnostico);  // Use %49s instead of %s
    printf("Diagnóstico lido: %s\n", l->diagnostico);

    printf("REGIAO DO CORPO:\n");
    scanf(" %19[^\n]", l->regiao);  // Use %19s instead of %s
    printf("Região lida: %s\n", l->regiao);

    printf("TAMANHO:\n");
    scanf("%d", &l->tamanho);
    printf("Tamanho lido: %d\n", l->tamanho);

    printf("ENVIAR PARA CIRURGIA:\n");
    scanf("%d", &l->cirurgia);
    printf("Enviar para cirurgia lido: %d\n", l->cirurgia);

    printf("ENVIAR PARA CRIOTERAPIA:\n");
    scanf("%d", &l->crioterapia);
    printf("Enviar para crioterapia lido: %d\n", l->crioterapia);

}

tLesao* copiaLesao(tLesao* a)
{
    tLesao* b = criaLesao();
    b -> id = a -> id;
    strcpy(b -> diagnostico, a -> diagnostico);
    strcpy(b -> regiao, a -> regiao);
    b -> tamanho = a -> tamanho;
    b -> cirurgia = a -> cirurgia;
    b -> crioterapia = a -> crioterapia;
    return b;
}

void printLesao(tLesao* l)
{

}

void escreveBinLesao(tLesao* lesao, FILE* arquivo)
{
    fwrite(lesao->rotulo, sizeof(char), sizeof(lesao->rotulo), arquivo);
    fwrite(&(lesao->id), sizeof(int), 1, arquivo);
    fwrite(lesao->diagnostico, sizeof(char), sizeof(lesao->diagnostico), arquivo);
    fwrite(lesao->regiao, sizeof(char), sizeof(lesao->regiao), arquivo);
    fwrite(&(lesao->tamanho), sizeof(int), 1, arquivo);
    fwrite(&(lesao->cirurgia), sizeof(int), 1, arquivo);
    fwrite(&(lesao->crioterapia), sizeof(int), 1, arquivo);
}

void lerBinLesao(tLesao* lesao, FILE* arquivo)
{
    fread(lesao->rotulo, sizeof(char), sizeof(lesao->rotulo), arquivo);
    fread(&(lesao->id), sizeof(int), 1, arquivo);
    fread(lesao->diagnostico, sizeof(char), sizeof(lesao->diagnostico), arquivo);
    fread(lesao->regiao, sizeof(char), sizeof(lesao->regiao), arquivo);
    fread(&(lesao->tamanho), sizeof(int), 1, arquivo);
    fread(&(lesao->cirurgia), sizeof(int), 1, arquivo);
    fread(&(lesao->crioterapia), sizeof(int), 1, arquivo);
}

char* obtemRotuloLesao(tLesao* l)
{
    return l -> rotulo;
}

void defineRotuloLesao(tLesao* l, const char* rotulo)
{
    strcpy(l -> rotulo, rotulo);
}

int obtemIdLesao(tLesao* l)
{
    return l -> id;
}

void defineIdLesao(tLesao* l, int id)
{
    l -> id = id;
}

char* obtemDiagnosticoLesao(tLesao* l)
{
    if (l != NULL)
        return l -> diagnostico;

    return "errou";
}

char* obtemRegiaoLesao(tLesao* l)
{
    if (l != NULL)
        return l -> regiao;

    return "errou";
}

int obtemTamanhoLesao(tLesao* l)
{
    if (l != NULL)
        return l -> tamanho;

    return 0;
}

bool obtemCirurgiaLesao(tLesao* l)
{
    if (l -> cirurgia > 0)
    {
        return true;
    }
    return false;
}

bool obtemCrioterapiaLesao(tLesao* l)
{
    if(l -> crioterapia > 0)
    {
        return true;
    }
    return false;
}

void desalocaLesao(tLesao* l)
{
    free(l);
}