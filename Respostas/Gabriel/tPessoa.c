#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tPessoa.h"

struct tPessoa{
	char nome[100];
	char cpf[20];
	char dataNascimento[15];
	char telefone[30];
	char genero[15];
};

tPessoa* criaPessoa()
{
	tPessoa* pessoa = (tPessoa*) calloc (1, sizeof(tPessoa));
	return pessoa;
}

void lerPessoa(tPessoa* p)
{
    scanf("%s", p -> nome);
    scanf("%s", p -> cpf);
    scanf("%s", p -> dataNascimento);
    scanf("%s", p -> telefone);
    scanf("%s", p -> genero);
}

void printPessoa(tPessoa* p)
{
    return;
}

void printNomeDataNascPessoa()
{
    return;
}

void escreveBinPessoa()
{

}

void lerBinPessoa()
{

}

bool comparaCPFPessoa(tPessoa* p, const char* cpf)
{
    return (!strcmp(p -> cpf, cpf));
}

char* obtemCPFPessoa(tPessoa* p)
{
	return p -> cpf;
}

char* obtemNomePessoa(tPessoa* p)
{
	return p -> nome;
}

int calculaIdadePessoa(tPessoa* p)
{
    // Data de referência
    const char dataReferencia[] = "09/11/2023";

    // Converter a data de referência para struct tm
    struct tm referencia;
    memset(&referencia, 0, sizeof(struct tm));

    if (sscanf(dataReferencia, "%d/%d/%d", &referencia.tm_mday, &referencia.tm_mon, &referencia.tm_year) != 3)
    {
        fprintf(stderr, "Erro ao converter a data de referência.\n");
        return -1; // Indica erro
    }
    referencia.tm_mon--; // Ajuste, pois os meses em struct tm começam de 0

    // Converter a data de nascimento para struct tm
    struct tm nascimento;
    memset(&nascimento, 0, sizeof(struct tm));

    if (sscanf(p->dataNascimento, "%d/%d/%d", &nascimento.tm_mday, &nascimento.tm_mon, &nascimento.tm_year) != 3)
    {
        fprintf(stderr, "Erro ao converter a data de nascimento.\n");
        return -1; // Indica erro
    }
    nascimento.tm_mon--; // Ajuste, pois os meses em struct tm começam de 0

    // Calcular a diferença de anos
    int idade;
    if (nascimento.tm_mon > referencia.tm_mon || (nascimento.tm_mon == referencia.tm_mon && nascimento.tm_mday > referencia.tm_mday))
    {
        idade = referencia.tm_year - nascimento.tm_year - 1;
    } else
    {
        idade = referencia.tm_year - nascimento.tm_year;
    }

    return idade;
}

bool comparaGeneroPessoa(tPessoa* p, const char* genero)
{
    return (!strcmp(p -> genero, genero));
}

void desalocaPessoa(tPessoa* p)
{
    free(p);
}