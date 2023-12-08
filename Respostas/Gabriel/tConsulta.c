#include <stdio.h>
#include <stdlib.h>
#include "tPaciente.h"
#include "tMedico.h"
#include "tLesao.h"
#include "tReceita.h"
#include "tConsulta.h"

struct tConsulta{
    int id;
    char data[20];
    tPaciente* paciente;
    tMedico* medico;
    int diabetes;
    int fumante;
    int alergia;
    int historicoCancer;
    char pele[3];
    tReceita* receita;
    tLesao** lesoes;
    int qtdLesoes;
};

tConsulta* criaConsulta()
{
    tConsulta* consulta = (tConsulta*) calloc (1, sizeof(tConsulta));
    return consulta;
}

void printConsulta(tConsulta* c)
{

}

void escreveBinConsulta(tConsulta* c)
{

}

void lerBinConsulta(tConsulta* c)
{

}

void adicionarLesaoConsulta(tConsulta* c)
{
    c -> qtdLesoes++;
    c -> lesoes = (tLesao**) realloc(c -> lesoes, c -> qtdLesoes * sizeof(tLesao*));
    c -> lesoes[c -> qtdLesoes-1] = criaLesao();
    lerLesao(c -> lesoes[c -> qtdLesoes-1]);
}

int obtemIdConsulta(tConsulta* c)
{
    return c -> id;
}

void defineIdConsulta(tConsulta* c, int id)
{
    c -> id = id;
}

int obtemQtdAtualLesaoConsulta(tConsulta* c)
{  
    return c -> qtdLesoes;
}

/*int obtemIdLesoesConsulta(tConsulta* c)
{

}*/

char* obtemDataConsulta(tConsulta* c)
{
    return c -> data;
}

void desalocaConsulta(tConsulta* c)
{
    desalocaPaciente(c -> paciente);
    desalocaMedico(c -> medico);
    desalocaReceita(c -> receita);
    for (int i = 0; i < c -> qtdLesoes; i++)
    {
        desalocaLesao(c -> lesoes[i]);
    }
    free(c -> lesoes);
    free(c);
}