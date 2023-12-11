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
    tRelatorio* relatorio = (tRelatorio*) malloc (1, sizeof(tRelatorio*));
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

void imprimeNaTelaRelatorio(tRelatorio* r)
{
    
}

void imprimeEmArquivoRelatorio(tRelatorio* r)
{

}