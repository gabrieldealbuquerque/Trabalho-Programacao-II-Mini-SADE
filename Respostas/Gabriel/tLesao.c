#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "tLesao.h"
#include <string.h>

struct tLesao{
    char rotulo[3];
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
    scanf("%49s", l->diagnostico);  // Use %49s instead of %s
    printf("REGIAO DO CORPO:\n");
    scanf("%19s", l->regiao);  // Use %19s instead of %s
    printf("TAMANHO:\n");
    scanf("%d", &l->tamanho);
    printf("ENVIAR PARA CIRURGIA:\n");
    scanf("%d", &l->cirurgia);
    printf("ENVIAR PARA CRIOTERAPIA:\n");
    scanf("%d", &l->crioterapia);
}

void printLesao(tLesao* l)
{

}

void escreveBinLesao(tLesao* l)
{

}

void lerBinLesao(tLesao* l)
{

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
    return l -> diagnostico;
}

char* obtemRegiaoLesao(tLesao* l)
{
    return l -> regiao;
}

int obtemTamanhoLesao(tLesao* l)
{
    return l -> tamanho;
}

bool obtemCirurgiaLesao(tLesao* l)
{
    return l -> cirurgia;
}

bool obtemCrioterapiaLesao(tLesao* l)
{
    return l -> crioterapia;
}

void desalocaLesao(tLesao* l)
{
    free(l);
}