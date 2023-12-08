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
    scanf("%s", l -> diagnostico);
    scanf("%s", l -> regiao);
    scanf("%d", &l -> tamanho);
    scanf("%d", &l -> cirurgia);
    scanf("%d", &l -> crioterapia);
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