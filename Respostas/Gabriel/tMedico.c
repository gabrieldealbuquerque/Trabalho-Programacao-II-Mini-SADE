#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPessoa.h"
#include "tLogin.h"
#include "tMedico.h" 

struct tMedico{
    tPessoa* dadosDoMedico;
    tLogin* login;
    int id;
    char CRM[12];
};

tMedico* criaMedico()
{
    tMedico* medico = (tMedico*) calloc (1, sizeof(tMedico));
    return medico;
}

void lerMedico(tMedico* m)
{
    LePessoa(m);
    scanf("%12s", medico -> crm);
}

void printMedico(tMedico* m, int qtdMedico)
{
    
}

void escreveBinMedico(tMedico* m)
{

}

bool comparaCPFMedico(tMedico* m, const char* cpf)
{
    return strcmp(obtemCPFMedico(m), cpf);
}

char* obtemCPFMedico(tMedico* m)
{
    return obtemCPFPessoa(m -> dadosDoMedico);
}

char* obtemIdMedico(tMedico* m)
{
    return m -> id;
}

char* obtemNomeMedico(tMedico* m)
{
    return obtemCPFPessoa(m -> dadosDoMedico);
}

char* obtemCRMMedico(tMedico* m)
{
    return m -> crm;
}

void defineIdMedico(tMedico* m)
{
    scanf("%d", &m -> id);
}

void desalocaMedico(tMedico* m)
{
    desalocaPessoa(m -> dadosDoMedico);
    desalocaLogin(m -> login);
    free(m);
}
